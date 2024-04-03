import article_citations;
import <iostream>;

using namespace std;

void processCitations(ArticleCitations cit)
{
	cout << cit.getArticle() << endl;
	for (int i{ 0 }; i < cit.getNumCitations(); i++) {
		cout << cit.getCitation(i) << endl;
	}
}

int main()
{
	while (true) {
		cout << "Enter a file name (\"STOP\" to stop): ";
		string filename;
		cin >> filename;
		if (filename == "STOP") { break; }

		ArticleCitations cit{ filename };
		processCitations(cit);
	}
}
