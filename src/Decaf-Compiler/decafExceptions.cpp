struct repeated_var_declaration : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to repeated variable declaration in the same scope.";
   }
};

struct missing_main_function : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to absence of main function.";
   }
};

struct main_containing_params : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated as method arguments are not allowed in the main function.";
   }
};

struct array_size : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated as non-positive array size is not allowed.";
   }
};

struct break_without_for : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated as break statement should be within a for loop.";
   }
};

struct continue_without_for : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated as continue statement should be within a for loop.";
   }
};

struct array_not_declared : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to use of an undeclared array.";
   }
};

struct variable_not_declared : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to use of an undeclared variable.";
   }
};

struct invalid_array_subscript : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to use of an invalid array subscript.";
   }
};

struct invalid_if_condition : public std::exception {
   const char * what () const throw () {
      return "Compilation terminated due to invalid type of condition in if statment.";
   }
};