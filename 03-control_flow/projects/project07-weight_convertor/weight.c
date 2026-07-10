#include <stdio.h>

#define KG_TO_LBS 2.20462

int main() {

    double user_weight_kg;
    double user_weight_lbs;

    //kgs
    printf("how much do you weigh in KG?: ");
    scanf("%lf", &user_weight_kg);
    
    double conv_to_lbs = user_weight_kg * KG_TO_LBS;
    printf("%.2lf kgs in lbs is %.2lf\n", user_weight_kg, conv_to_lbs);

    //lbs
    printf("how much do you weigh in pounds?: ");
    scanf("%lf", &user_weight_lbs);

    double conv_to_kgs = user_weight_lbs / KG_TO_LBS;
    printf("%.2lf lbs in kgs is %.2lf\n", user_weight_lbs, conv_to_kgs);

    return 0;
}