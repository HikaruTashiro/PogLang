void __assert_lexical_fail(const char *__assertion, const char *__file,
			   unsigned int __line, const char *__function, const char* message);


#define assert_lexical(expr, message) \
	(static_cast<bool>(expr) \
	 ? void(0) \
	 : __assert_lexical_fail(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__, message)) \

