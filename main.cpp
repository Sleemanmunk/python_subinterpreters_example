// Author: Baruch Sterin <baruchs@gmail.com>

#include <Python.h>

#include <string>
#include <vector>
#include <thread>

using namespace std;

const string INTERPRETER_ID = "INTERPRETER_ID";

int main() {
    Py_Initialize();
    PyThreadState *mainThreadState = PyThreadState_Get();

    vector<PyThreadState *> interpreters;

//For each interpreter instance (in any thread):

    for (int i = 0; i < 3; i++) {
// initialize interpreter
        PyThreadState *interpeter = Py_NewInterpreter();
        string code = R"PY(
val=0
interpreter_id="INTERPRETER_ID"
print (f"""Interpreter {interpreter_id} Initializing val to {val}""")
)PY";
        code.replace(code.find(INTERPRETER_ID), INTERPRETER_ID.size(), to_string(i));
        PyRun_SimpleString(code.c_str());

        interpreters.emplace_back(interpeter);
    }

    for (int j=0; j < 3; j++) {
        int i = 0;
        for (auto interpreter: interpreters) {
// continue with interpreter
            PyThreadState_Swap(interpreter); // get GIL + swap in thread state
            string code = R"PY(
val+=1
print (f"Interpreter {interpreter_id} has been called {val} times")
)PY";
            PyRun_SimpleString(code.c_str());
            i++;
        }
    }

    int i=0;
    for (auto interpreter:interpreters) {
// finish with interpreter
        PyThreadState_Swap(interpreter);
        string code = R"PY(
val+=1
print (f"Interpreter {interpreter_id} shutting down now...")
)PY";
        PyRun_SimpleString(code.c_str());
        Py_EndInterpreter(interpreter);
        i++;
    }

    PyThreadState_Swap(mainThreadState);
    Py_Finalize();


    return 0;
}
