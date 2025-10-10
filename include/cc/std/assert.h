#undef assert

#ifdef NDEBUG
#define assert(test) ((void)0)
#else
void _assert(char *);
/* (impl) The following _STR and _VAL macros are necessary because __LINE__
 * does not expand to a string literal; it becomes a decimal constant.
 */
#define _STR(x) _VAL(x)
#define _VAL(x) #x
#define assert(test)                                                           \
  ((test) ? (void)0                                                            \
          : _assert("Assertion failed: " #test ", file " __FILE__              \
                    ", line " _STR(__LINE__)))
#endif
