#include <iostream>
#include <vector>

using namespace std;

vector<double>* q_conj(const vector<double>& q){
    vector<double>* ans = new vector<double>(q.size());

    (*ans)[0] = q[0];
    for(int i = 1; i < 4; i++)
    {
        (*ans)[i] = -q[i];
    }
    return ans;
};



int main() {

    //Spacecraft Parameters
    vector<vector<double>> I = {                        //Inertia Matrix (kg*m^2
            {10, 0, 0},
            {0,15,0},
            {0,0,20}
    };
    vector<double> omega = {0.1,0.2,0.3};               //Initial angular velocity (rad/s)
    vector<double> q = {1,0,0,1};                       //Initial quaternion

    //Desired attitude
    vector<double> q_desired = {0.9239,0, 0.3827, 0};   //45-deg rotation about y-axis

    //PID control gains
    vector<double> Kp = {5,5,5};
    vector<double> Ki = {0.1,0.1,0.1};
    vector<double> Kd = {2,2,2};

    //Simulation Parameters
    double t0 = 0.0;
    double dt = 0.01;                                    //Time Step (s)
    double t_end = 10;                                   //Total simulation time (s)


    // Call the function and get the pointer to the new vector
    vector<double>* q_conjugate = q_conj(q);

    // Access values using pointer
    cout << "Conjugated vector: ";
    for (double val : *q_conjugate) {
        cout << val << " ";
    }
    cout << endl;

//    // Simulation loop
//    for (double t = t0; t <= t_end; t += dt) {
//        //Compute attitude error
//
//        // Call the function and get the pointer to the new vector
//        vector<double>* q_conjugate = q_conj(q);
//
//        // Access values using pointer
//        cout << "Conjugated vector: ";
//        for (double val : *q_conjugate) {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
}
