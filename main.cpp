#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "histogram.h"
#include "svg_module.h"

using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

vector <size_t> make_histogram(const vector<double> & numbers, size_t bin_count, double min, double max)
{
    find_minmax(numbers,min,max);
    vector<size_t> bins(bin_count,0);
    for (double number : numbers)
    {
        size_t bin;
        bin = (number - min) / (max - min) * bin_count;
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

void make_histogram(const vector<double>& numbers, double& max, double& min, size_t bin_count, vector <size_t>& bins )
{

    for(double x: numbers)
    {
        size_t bin_index=(x-min)/(max-min)*bin_count;
        if (bin_index==bin_count)
        {
            bin_index--;
        }
        bins[bin_index]++;
    }
}
void show_histogram_text(vector <size_t>& bins)
{
    size_t max_bin = bins[0];
    for (size_t bin:bins)
    {
        if (bin > max_bin)
        {
            max_bin=bin;
        }
    }
    if (max_bin > MAX_ASTERISK)
    {
        double factor = MAX_ASTERISK/static_cast<double>(max_bin);
        for (size_t bin:bins)
        {
            if (bin <100)
            {
                cout<<" ";
                if (bin < 10)
                {
                    cout<<" ";
                }
            }
            cout <<bin <<"|";
            size_t height = bin*factor;
            for(int i=0; i<height; i++)
            {
                cout<< "*";
            }
            cout<<endl;
        }
    }

    else
    {
        for (size_t bin:bins)
        {
            if (bin <100)
            {
                cout<<" ";
                if(bin < 10)
                {
                    cout<<" ";
                }
            }
        cout<<bin<<"|";
        for (int i = 0; i < bin; i++)
        {
            cout << "*";
        }
        cout<<endl;
        }
    }
}
int main() {

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

       if (number_count == 0) {
        cerr << "ERROR: Empty vector";
    } else {

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    vector<string> colors(bin_count);

    for(size_t i = 0; i < bin_count; i++) {
		cerr << "Enter column's number" << i << " color: ";
		cin >> colors[i];
	}

    double min, max;

    find_minmax(numbers, min, max);
    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins, colors);

    }
    return 0;
}
