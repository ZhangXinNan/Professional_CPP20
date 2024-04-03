import <string>;
import <format>;

using namespace std;

int main()
{
	int n{ 42 };

	auto s1{ format("Read {} bytes from {}", n, "file1.txt") };
	auto s2{ format("Read {0} bytes from {1}", n, "file1.txt") };
	auto s3{ format(L"从{1}中读取{0}个字节。", n, L"file1.txt") };
}
