void ThirdPartyLibraryMethod(char* str) {}

void f(const char* str)
{
	ThirdPartyLibraryMethod(const_cast<char*>(str));
}

int main()
{
	f("Hello World");
}
