import <iostream>;
import <exception>;
import <vector>;

using namespace std;

// Throws a logic_error exception if the number of elements
// in the given dataset is not even.
void verifyDataSize(const vector<int>& data)
{
    if (data.size() % 2 != 0)
		throw logic_error{ "Number of data points must be even." };
}

// Throws a logic_error exception if the number of elements
// in the given dataset is not even.
// Throws a domain_error exception if one of the datapoints is negative.
void processData(const vector<int>& data)
{
    // Verify the size of the given dataset.
    try {
        verifyDataSize(data);
    } catch (const logic_error& /*caughtException*/) {
        // Write message on standard error output.
        cerr << "Invalid number of data points in dataset. Aborting." << endl;
        // And rethrow the exception.
        
        ////throw caughtException;
        //// To rethrow an exception, you should just use "throw;"
        throw;
    }
    // Verify for negative datapoints.
    for (auto& value : data) {
        if (value < 0)
			throw domain_error{ "Negative datapoints not allowed." };
    }
    // Process data ...
}

int main()
{
    try {
        vector data{ 1, 2, 3, -5, 6, 9 };
        processData(data);
    ////} catch (const logic_error& caughtException) {
    ////    cerr << "logic_error: " << caughtException.what() << endl;
    ////} catch (const domain_error& caughtException) {
    ////    cerr << "domain_error: " << caughtException.what() << endl;
    ////}
    //// If you carefully look at Figure 14-3, you'll see that domain_error
    //// is a derived class from logic_error. So, the above order of catch
    //// statements is wrong: you should first catch the more specific
    //// exception class, then a more general. So the order needs to be reversed:
    } catch (const domain_error& caughtException) {
        cerr << "domain_error: " << caughtException.what() << endl;
    } catch (const logic_error& caughtException) {
        cerr << "logic_error: " << caughtException.what() << endl;
    }
}
