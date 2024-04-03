import <thread>;

using namespace std;

int main()
{
	jthread job{ [](stop_token token) {
		while (!token.stop_requested()) {
			//...
		}
	} };

	job.request_stop();
}