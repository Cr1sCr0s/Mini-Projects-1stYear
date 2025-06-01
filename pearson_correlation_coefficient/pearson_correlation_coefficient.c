#include<stdio.h>
#include <math.h> //for sqrt() & pow()
// 03/11/25

// Function to print the Pearson correlation coefficient
void printMatrix(double mat[11][5]) {

    printf("\n--------------------------------------------------------------\n");
    printf("x\t|\ty\t|\tx^2\t|\ty^2\t|\txy\n"); 
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f\n", 
               mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
    }

    printf("--------------------------------------------------------------\n");
    
    printf("%.2f\t|\t%.2f\t|\t%.2f\t|\t%.2f|\t%.2f\n",mat[10][0],mat[10][1],mat[10][2],mat[10][3],mat[10][4]);
    printf("--------------------------------------------------------------\n\n");
}


// Function to compute the Pearson correlation coefficient
double pearson_correlation(double column1[10], double column2[10], double mat[11][5]) {
    //variables
    int i, n = 10;
    double sumX = 0, sumY = 0, sumXSquared = 0, sumYSquared = 0, sumXY = 0;

    for(i=0; i < n; i++) {
        //compute sum
    	sumX += column1[i];
        sumY += column2[i];
        sumXSquared += pow(column1[i], 2);
        sumYSquared += pow(column2[i], 2);
        sumXY += (column1[i] * column2[i]);

        //values to matrix
        mat[i][0] = column1[i];
        mat[i][1] = column2[i];
        mat[i][2] = pow(column1[i], 2);
        mat[i][3] = pow(column2[i], 2);
        mat[i][4] = column1[i] * column2[i];
    }
    
    //store to last row, total
    mat[10][0] = sumX;
    mat[10][1] = sumY;
    mat[10][2] = sumXSquared;
    mat[10][3] = sumYSquared;
    mat[10][4] = sumXY;

    // formula
    double numerator = (n * sumXY) - (sumX * sumY);
    double denominator = sqrt((n * sumXSquared - pow(sumX, 2)) * (n * sumYSquared - pow(sumY, 2)));
    double r = numerator / denominator;
    
	//test
    /*
    printf("\nSumX: %.2lf, SumY: %.2lf, SumXSquared: %.2lf, SumYSquared: %.2lf, SumXY: %.2lf\n", sumX, sumY, sumXSquared, sumYSquared, sumXY);
    printf("Numerator: %.2lf, Denominator: %.2lf, Pearson Correlation Coefficient: %.2lf\n\n", numerator, denominator, r);
    */

    //calls printMatrix function
    printMatrix(mat);

    return r; //returns result of formula e.g. 0.47
}

// Function for interpretation
void interpretation(double correlation) {

    if (correlation > 0.5) {
    	printf("Strength: Strong \n");
    	printf("Direction: Positive \n");
    }
    else if (correlation > 0.3 && correlation < 0.5) {
    	printf("Strength: Moderate \n");
    	printf("Direction: Positive \n");
    }
    else if (correlation > 0.0 && correlation < 0.3) {
    	printf("Strength: Weak \n");
    	printf("Direction: Positive \n");
    }
    else if (correlation == 0) {
    	printf("Strength: None \n");
    	printf("Direction: None \n");
    }
    else if (correlation > -0.3 && correlation < 0) {
    	printf("Strength: Weak \n");
    	printf("Direction: Negative \n");
    }
    else if (correlation > -0.5 && correlation < -0.3) {
    	printf("Strength: Moderate \n");
    	printf("Direction: Negative \n");
    }
    else if (correlation < -0.5) {
    	printf("Strength: Strong \n");
    	printf("Direction: Negative \n");
    }

	return;
}

int main() {
    // Define the arrays for the first and second columns
    double column1[] = {3.63, 3.02, 3.82, 3.42, 3.59, 2.87, 3.03, 3.46, 3.36, 3.30};
    double column2[] = {53.1, 49.7, 48.4, 54.2, 54.9, 43.7, 47.2, 45.2, 54.4, 50.4};
    
    // 2D array to store computations
    double mat[11][5] = {0};
    
    // Determine the number of rows (assumed both columns have the same length)
    int num_rows = 10;

    // Print the array with 2 columns
    printf("\nWeight(Kg)\tLength(cm))\n");
    for(int i = 0; i < num_rows; i++) {
    	printf("%.2lf\t\t%.2lf\n", column1[i], column2[i]);
    }

    // Calculate Pearson correlation coefficient
    double correlation = pearson_correlation(column1, column2, mat);
    
    printf("Pearson Correlation Coefficient: %.2f\n\n", correlation);

    //print interpretation here
    interpretation(correlation);

    return 0;
}

