/* UVa problem: 10026
 *
 * Topic: Sorting
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Sort the job and finish by smallest cost.
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Tianyu Zhang
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct job {
	int time;
	int fine;
	int index;
};

bool comp( job a, job b ) {
	return a.time * b.fine < b.time * a.fine;
}

int main() {

	int test_case;

	cin >> test_case;

	for ( int case_number = 0; case_number < test_case; case_number++ ) {

		int job_number;
		vector<job> jobs;

		cin >> job_number;

		for ( int i = 0; i < job_number; i++ ) {

			job current_job;
			cin >> current_job.time >> current_job.fine;
			current_job.index = i;
			jobs.push_back( current_job );

		}

		stable_sort( jobs.begin(), jobs.end(), comp );

		for ( int i = 0; i < job_number - 1; i++ ) 
			cout << jobs[i].index + 1 << " ";

		cout << jobs[job_number - 1].index + 1 << endl;

		if ( case_number != test_case - 1 ) cout << endl;

	}

	return 0;

}
