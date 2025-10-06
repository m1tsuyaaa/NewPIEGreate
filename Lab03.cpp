/*************************
 * Name:    Katkov Stepan*
 * Project: Lab03        *
 * Var 8                 *
 *************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Константы для газовых параметров
    const double gasDensity = 0.0011;
    const double gasViscosity = 0.00018;
    
    // Константы для жидкостей
    const double alcoholDensity = 0.79;
    const double alcoholViscosity = 0.012;
    const double anilineDensity = 1.03;
    const double anilineViscosity = 0.04;
    const double glycerinDensity = 1.26;
    const double glycerinViscosity = 13.5;
    
    // Константы для расчетов
    const double coefficientA1 = 2.03;
    const double coefficientA2 = 2.15;
    const double baseValue = 0.8;
    const double exponent1 = 0.26;
    const double exponent2 = 0.16;
    const double exponent3 = 0.05;
    const double thresholdK = 0.5;
    const double testViscosityRatio = 1.0;
    const double denominatorBase = 1.0;
    
    // Константы для циклов
    const int totalLiquids = 5;
    const int tableLiquids = 3;
    const int alcoholIndex = 0;
    const int anilineIndex = 1;
    const int glycerinIndex = 2;
    const int testIndex = 3;
    const int aWidth = 12;

    // Переменные для расчетов
    double gammaRatio;
    double viscosityRatio;
    double kParameter;
    double phiResult;
    double liquidDensity;
    double liquidViscosity;
    const char* liquidName;

    // Счётчик
    int liquidCounter;

    for (liquidCounter = 0; liquidCounter < totalLiquids; ++liquidCounter) {
        bool isTestCase;
        
        if (liquidCounter == alcoholIndex) {
            liquidDensity = alcoholDensity;
            liquidViscosity = alcoholViscosity;
            isTestCase = false;
        } else if (liquidCounter == anilineIndex) {
            liquidDensity = anilineDensity;
            liquidViscosity = anilineViscosity;
            isTestCase = false;
        } else if (liquidCounter == glycerinIndex) {
            liquidDensity = glycerinDensity;
            liquidViscosity = glycerinViscosity;
            isTestCase = false;
        } else if (liquidCounter == testIndex) {
            liquidName = "Тест (K=0.5)";
            isTestCase = true;
        } else {
            continue;
        }

        if (isTestCase) {
            gammaRatio = thresholdK;
            viscosityRatio = testViscosityRatio;
            kParameter = gammaRatio * viscosityRatio;
        } else {
            gammaRatio = gasDensity / liquidDensity;
            viscosityRatio = liquidViscosity / gasViscosity;
            kParameter = gammaRatio * viscosityRatio;
        }

        if (kParameter < thresholdK) {
            phiResult = baseValue / (denominatorBase + coefficientA1 * pow(gammaRatio, exponent1) * pow(viscosityRatio, exponent3));
        } else {
            phiResult = baseValue / (denominatorBase + coefficientA2 * pow(gammaRatio, exponent2) * pow(viscosityRatio, exponent3));
        }
    }

    for (int resultCounter = 0; resultCounter < tableLiquids; ++resultCounter) {
        double currentLiquidDensity;
        double currentLiquidViscosity;

        if (resultCounter == alcoholIndex) {
            currentLiquidDensity = alcoholDensity;
            currentLiquidViscosity = alcoholViscosity;
        } else if (resultCounter == anilineIndex) {
            currentLiquidDensity = anilineDensity;
            currentLiquidViscosity = anilineViscosity;
        } else {
            currentLiquidDensity = glycerinDensity;
            currentLiquidViscosity = glycerinViscosity;
        }
        
        gammaRatio = gasDensity / currentLiquidDensity;
        viscosityRatio = currentLiquidViscosity / gasViscosity;
        kParameter = gammaRatio * viscosityRatio;

        if (kParameter < thresholdK) {
            phiResult = baseValue / (denominatorBase + coefficientA1 * pow(gammaRatio, exponent1) * pow(viscosityRatio, exponent3));
        } else {
            phiResult = baseValue / (denominatorBase + coefficientA2 * pow(gammaRatio, exponent2) * pow(viscosityRatio, exponent3));
        }

        cout << setw(aWidth) << phiResult << setw(aWidth) << kParameter << endl;
    }

    return 0;
}