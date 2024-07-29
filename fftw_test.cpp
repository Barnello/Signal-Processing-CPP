#include <iostream>
#include <fftw3.h>

int main(){

    int N = 10;
    double in[N];
    fftw_complex out[N];
    fftw_plan p;

    // Initializing the input data
    for (int i = 0; i < N; ++i){
        in[i] = i;
    }

    // Create plan for FFT
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

    fftw_execute(p);

    std::cout << "FFT result" << std::endl;
    for(int i = 0; i < N; ++i){
        std::cout << out[i][0] << " + " << out[i][1] << "i" << std::endl;
    }

    fftw_destroy_plan(p);
    fftw_cleanup();

    return 0;
}