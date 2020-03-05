#include <iostream>
#include <chrono>

// Calculate the product of a matrix and a vector. The value of the elements of
// outv, the output vector can be calculated from the values of matrix and an
// input vector inv as:
// outv[i] = sum_over_j(matrix[i][j] * inv[j])

void initialize(double **&, double *&, double *&, int);

int main ( ) {
	double **matrix;
	double *outv, *inv;

	// Set the size of the matrix and vectors
	int n = 10000;

	// Fill the entries of the matrix and inv, and allocate the memory for outv
	initialize(matrix, inv, outv, n);

	// matrix is a two dimensional nxn array, inv and out v are one dimensional
	// n length arrays
  
	// Zero out the elements of outv
	for (auto i = 0; i < n; i++) {
		outv[i] = 0.0;
	}

	// Start the timer
	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Calculate one contribution to an element of outv, accessing an element
			// of matrix as matrix[i][j]
		}
	}

	// Stop the timer
	auto stop = std::chrono::steady_clock::now();

	// Report the result
	std::cout << "Multiplication indexed as [i][j] took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << std::endl;

	// Zero out the elements of outv
	for (auto i = 0; i < n; i++) {
		outv[i] = 0.0;
	}
  
	// Start the timer
	start = std::chrono::steady_clock::now();
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Calculate one contribution to an element of outv, accessing an element
			// of matrix as matrix[j][i]
		}
	}

	// Stop the timer
	stop = std::chrono::steady_clock::now();

	// Report the result
	std::cout << "Multiplication indexed as [j][i] took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << std::endl;

  
	return 0;
}

void initialize(double **&matrix, double *&inv, double *&outv, int n) {
	matrix = new double*[n];

	inv = new double[n];
	outv = new double[n];
  
	for (auto i = 0; i < n; i++) {
		double* line = new double[n];
		matrix[i] = line;
		inv[i] = static_cast<double>(i);
		for (auto j = 0; j < n; j++) {
			line[j] = (i==j) ? 1.0 : 0.0;
		}
	}
	return;
}
