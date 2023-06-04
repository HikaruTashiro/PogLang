void __assert_lexical_error(const char *__assertion, const char *__file,
			   unsigned int __line, const char *__function, const char* message);

void __assert_syntax_error(const char *__assertion, const char *__file,
			   unsigned int __line, const char *__function, const char* message);


#define assert_lexical(expr, message) \
	(static_cast<bool>(expr) \
	 ? void(0) \
	 : __assert_lexical_error(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__, message)) \


#define assert_syntax(expr, message) \
	(static_cast<bool>(expr) \
	 ? void(0) \
	 : __assert_syntax_error(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__, message)) \


