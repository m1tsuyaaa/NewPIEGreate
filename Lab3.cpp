/*************************
 * Name:    Katkov Stepan*
 * Project: Lab03        *
 * Var 8                 *
 * ***********************/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    const double gasDensity = 0.0011;
    const double gasViscosity = 0.00018;

    double gammaRatio, viscosityRatio, kParameter, phiResult;
    double liquidDensity, liquidViscosity;
    const char* liquidName;

    int liquidCounter = 1;
    while (liquidCounter <= 2) {
        
        if (liquidCounter == 1) {
            liquidName = "Спирт";
            liquidDensity = 0.79;
            liquidViscosity = 0.012;
        } else {
            liquidName = "Анилин";
            liquidDensity = 1.03;
            liquidViscosity = 0.04;
        }
        
        gammaRatio = gasDensity / liquidDensity;
        viscosityRatio = liquidViscosity / gasViscosity;
        kParameter = gammaRatio * viscosityRatio;
        
        if (kParameter < 0.5) {
            phiResult = 0.8 / (1.0 + 2.03 * pow(gammaRatio, 0.26) * pow(viscosityRatio, 0.05));
        } else {
            phiResult = 0.8 / (1.0 + 2.15 * pow(gammaRatio, 0.16) * pow(viscosityRatio, 0.05));
        }
        
        std::cout << liquidName << ":\n";
        std::cout << "  γ_г/γ_ж = " << gammaRatio << "\n";
        std::cout << "  μ_ж/μ_г = " << viscosityRatio << "\n";
        std::cout << "  K = " << kParameter << "\n";
        std::cout << "  φ = " << phiResult << "\n\n";
        
        liquidCounter++;
    }
    
    int testCounter = 0;
    do {
        if (testCounter == 0) {
            liquidName = "Глицерин";
            liquidDensity = 1.26;
            liquidViscosity = 13.5;
        } else {
            liquidName = "Тест (K=0.5)";
            gammaRatio = 0.5;
            viscosityRatio = 1.0;
            kParameter = gammaRatio * viscosityRatio;
            
            if (kParameter < 0.5) {
                phiResult = 0.8 / (1.0 + 2.03 * pow(gammaRatio, 0.26) * pow(viscosityRatio, 0.05));
            } else {
                phiResult = 0.8 / (1.0 + 2.15 * pow(gammaRatio, 0.16) * pow(viscosityRatio, 0.05));
            }
            
            std::cout << liquidName << ":\n";
            std::cout << "  γ_г/γ_ж = " << gammaRatio << "\n";
            std::cout << "  μ_ж/μ_г = " << viscosityRatio << "\n";
            std::cout << "  K = " << kParameter << "\n";
            std::cout << "  φ = " << phiResult << "\n\n";
            
            testCounter++;
            continue;
        }
        
        gammaRatio = gasDensity / liquidDensity;
        viscosityRatio = liquidViscosity / gasViscosity;
        kParameter = gammaRatio * viscosityRatio;
        
        if (kParameter < 0.5) {
            phiResult = 0.8 / (1.0 + 2.03 * pow(gammaRatio, 0.26) * pow(viscosityRatio, 0.05));
        } else {
            phiResult = 0.8 / (1.0 + 2.15 * pow(gammaRatio, 0.16) * pow(viscosityRatio, 0.05));
        }
        
        std::cout << liquidName << ":\n";
        std::cout << "  γ_г/γ_ж = " << gammaRatio << "\n";
        std::cout << "  μ_ж/μ_г = " << viscosityRatio << "\n";
        std::cout << "  K = " << kParameter << "\n";
        std::cout << "  φ = " << phiResult << "\n\n";
        
        testCounter++;
    } while (testCounter < 2);

    int resultCounter = 1;
    while (resultCounter <= 3) {
        
        if (resultCounter == 1) {
            liquidDensity = 0.79;
            liquidViscosity = 0.012;
        } else if (resultCounter == 2) {
            liquidDensity = 1.03;
            liquidViscosity = 0.04;
        } else {
            liquidDensity = 1.26;
            liquidViscosity = 13.5;
        }
        
        gammaRatio = gasDensity / liquidDensity;
        viscosityRatio = liquidViscosity / gasViscosity;
        kParameter = gammaRatio * viscosityRatio;
        
        if (kParameter < 0.5) {
            phiResult = 0.8 / (1.0 + 2.03 * pow(gammaRatio, 0.26) * pow(viscosityRatio, 0.05));
        } else {
            phiResult = 0.8 / (1.0 + 2.15 * pow(gammaRatio, 0.16) * pow(viscosityRatio, 0.05));
        }
        
        std::cout << std::setw(8) << phiResult << "    " << std::setw(8) << kParameter << std::endl;
        resultCounter++;
    }
    
    return 0;
}