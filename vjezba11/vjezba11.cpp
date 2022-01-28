#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int minElement(vector<int> v1)
{
    return *min_element(v1.begin(), v1.end());
}

int maxElement(vector<int> v1)
{
    return *max_element(v1.begin(), v1.end());
}

void sorting(vector<int>& v1)
{
    sort(v1.rbegin(), v1.rend());
}


int main()
{
    vector<int> v1;
    try
    {
        ifstream numFile;
        numFile.open("number.txt");
        
        int cnt = 0;

        istream_iterator<int> it1(numFile);
        istream_iterator<int> it2(numFile);
        copy(it1, it2, back_inserter(v1));

        for (int n : v1)
        {
            if (n > 500)
                cnt++;
        }

        cout << "There are " << cnt << " numbers over 500." << endl;
        cout << "Smallest number is: " << minElement(v1) << endl;
        cout << "Highest number is: " << maxElement(v1) << endl;

        v1.erase(remove_if(v1.begin(), v1.end(), [](const int& n) {return n < 300; }));

        sorting(v1);
    }

    catch (const ifstream::failure& ex)
    {
        cout << ex.what();
    }

    return 0;
}
