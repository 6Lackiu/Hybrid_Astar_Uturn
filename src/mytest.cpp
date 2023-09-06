#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main() {
    Eigen::VectorXd x_values(5);
    Eigen::VectorXd y_values(5);
    x_values << 1, 2, 3, 4, 5;
    y_values << 2, 3, 4, 5, 6;
    int order = 4;

    Eigen::MatrixXd A(x_values.size(), order + 1);

    // Build polynomial matrix A:
    for (int i = 0; i < x_values.size(); i++) {
        A(i, 0) = 1.0;
    }
    for (int j = 0; j < x_values.size(); j++) {
        for (int i = 0; i < order; i++) {
            A(j, i + 1) = A(j, i) * x_values(j);
        }
    }

    std::cout << "A:" << std::endl << A << std::endl << std::endl;

    auto Q = A.householderQr();
    auto result = Q.solve(y_values);

    std::cout << "res:" << std::endl << result << std::endl << std::endl;

    return 0;
}