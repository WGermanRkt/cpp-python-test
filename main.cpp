#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <vector>
#include <Python.h>

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int main(int argc, char** argv)
{
   std::cout << "DlogProcessor" << std::endl;

   std::string str = "from time import time,ctime\\n"
      "print('Today is', ctime(time()))\n";
   str = ReplaceAll( str, "\\n", "\n");

   std::vector<std::string> all_args;
   if (argc > 1) {
      all_args.assign(argv + 1, argv + argc);
      str = all_args[0];
      str = ReplaceAll( str, "\\n", "\n");
   }


   wchar_t *program = Py_DecodeLocale(argv[0], NULL);
   if (program == NULL) 
   {
      fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
      exit(1);
   }
   Py_SetProgramName(program);  /* optional but recommended */
   Py_Initialize();

   PyRun_SimpleString(str.c_str());

   if (Py_FinalizeEx() < 0) 
   {
      exit(120);
   }
   PyMem_RawFree(program);
   return 0;
}
