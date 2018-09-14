/*
 * En este programa obtenemos el índice de masa corporal del usuario que proporciona sus datos.
 *
 * Fórmula para calcular BMI:
 * BMI = weight / height^2
 *
 * Fecha: 13 de septiembre de 2018.
 * Autor: Alejandro Ramírez
 * Correo: alex.ramirez.99@hotmail.com / A01412034@itesm.mx
 */

#include <stdio.h>
#include <math.h>

// función para obtener el BMI en sistema métrico
void BMIkgm (double h, double w, double* BMI) {
    *BMI = w / pow(h,2);       // pow = elevar potencia
}

// funcion para obtener el BMI en sistema imperial
void BMIimp (double h, double w, double* BMI) {
    w = w * 0.453592;
    h = h * 0.3048;
    *BMI = w / pow(h,2);
}

// funcion para decir al usuario acerca de su bmi
void nivelPeso (double BMI) {
    printf("Your BMI is: %lf \n\n", BMI);
    printf("According to your BMI, you are: \n");
    if (BMI < 18.5) printf("Low BMI, try to eat more!\n");
    else {
        if (BMI >= 18.5 && BMI <= 24.9) printf("Normal BMI. Keep it like that!\n");
        if (BMI >= 25.0 && BMI <= 29.9) printf("You are Overweight, stop right there!\n");
        if (BMI >= 30.0) printf("You are Obese, eat healthier!");
    }

}

int main(void) {
    double weight = 0.0;
    double height = 0.0;
    double BMI = 0.0;
    int option;

    // menu para elegir qué tipo de sistema de medición desean
    printf("Hello, I will help you calculate your BMI.\n");
    printf("First of all, which measuring system do you prefer?\n");
    printf("Press 1 for metric system.\n");
    printf("Press 2 for imperial system.\n");
    printf("Press 0 to exit.\n");
    scanf("%i", &option);

    switch(option) {
        case 1:
            printf("Give me your height in meters: \n");
            scanf("%lf", &height);
            printf("Give me your weight in kilograms: \n");
            scanf("%lf", &weight);

            BMIkgm(height, weight, &BMI);
            break;

        case 2:
            printf("Give me your height in ft: \n");
            scanf("%lf", &height);
            printf("Give me your weight in pounds: \n");
            scanf("%lf", &weight);

            BMIimp(height, weight, &BMI);
            break;

        default:
            printf("Goodbye!\n");
            return 0;

    }

    // le doy al usuario su resultado
    nivelPeso(BMI);


    return 0;
}