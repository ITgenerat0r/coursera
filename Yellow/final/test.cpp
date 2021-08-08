Compile error: Error while compiling unit-tests for contents of file date.h. Details: Compile error: b'/tmp/submissionci1xka83/main.cpp:114:5: fatal error: static_assert failed due to requirement 
std::is_convertible_v<belts::nonesuch, Date>
 "Function Date ParseDate(istream&) not found in your submission"
    CHECK_FUNCTION(ParseDate, Date, istream&);
    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
include/detector.h:257:3: note: expanded from macro 
CHECK_FUNCTION
  __CHECK_FUNCTION_IMPL(__COUNTER__, function_name, return_type, ##__VA_ARGS__)
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
include/detector.h:120:3: note: expanded from macro 
__CHECK_FUNCTION_IMPL
  __CHECK_FUNCTION_IMPL_2(suffix, function_name, return_type, ##__VA_ARGS__)
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
include/detector.h:96:3: note: expanded from macro 
__CHECK_FUNCTION_IMPL_2
  static_assert(                                                                            
  ^
1 error generated.
'