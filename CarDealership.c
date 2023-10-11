#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 5

struct Car {
    char* Manufacturer;
    char* make;
    char * model;
    int price;

};
float affordableVehicle(int priceV, int priceD, float Q) {
    int P = priceV - priceD;
    float monthlyP = ((P + (P * Q * R)) / (R*12));
    return monthlyP;
}
void sortPrice(struct Car carPrice[],int numS)
   { 
        int i, j;
        struct Car temp;

        for (i = 0; i < numS-1; i++) {
            for (j = 0; j < numS-i-1; j++) {
                if (carPrice[j].price < carPrice[j+1].price) {
                    temp = carPrice[j];
                    carPrice[j] = carPrice[j+1];
                    carPrice[j+1] = temp;
            }
        }
    }
 }
 char* copyString(char s[])
{
    char* s2;
    s2 = (char*)malloc(20);
 
    strcpy(s2, s);
    return (char*)s2;
}


int main(int argc, char*argv[]){
struct Car carArray[]={
{"Toyota","Toyota","Corolla",21550},
{"Toyota","Toyota","Camry",25945},
{"Toyota","Toyota","Avalon",36825},
{"Toyota","Toyota","Mirai",49500},
{"Toyota","Toyota","Sequoia",58300},
{"Toyota","Toyota","Tacoma",27250},
{"Toyota","Toyota","Tundra",36965},
{"Toyota","Lexus","IS",40585},
{"Toyota","Lexus","ES",42490},
{"Toyota","Lexus","GX",57575},
{"Chevrolet","Chevy","Trailblazer",22100},
{"Chevrolet","Chevy","Camaro",26100},
{"Chevrolet","Chevy","Equinox",26600},
{"Chevrolet","Chevy","Traverse",34520},
{"Chevrolet","Chevy","Tahoe",54200},
{"Chevrolet","Chevy","Suburban",56900},
{"Chevrolet","Chevy","Corvette",64500},
{"Chevrolet","Chevy","Spark",13600},
{"Chevrolet","Chevy","Trax",21700},
{"Chevrolet","Chevy","Malibu",23400},
{"Nissan","Nissan","Versa",18990},
{"Nissan","Nissan","Sentra",22700},
{"Nissan","Nissan","Altima",35385},
{"Nissan","Nissan","Maxima",43300},
{"Nissan","Nissan","Pathfinder",50660},
{"Nissan","Nissan","Rogue",38640},
{"Nissan","Nissan","Murano",46910},
{"Nissan","Infiniti","Q50",42650},
{"Nissan","Infiniti","QX55",49150},
{"Nissan","Infiniti","QX80",72700},
{"BMW","BMW","2 Series Coupe",38050},
{"BMW","BMW","3 Series Sedan",48220},
{"BMW","BMW","4 Series Convertible",59320},
{"BMW","BMW","5 Series Sedan",55175},
{"BMW","BMW","7 Series Sedan",93400},
{"BMW","BMW","X1",39700},
{"BMW","BMW","X3",46050},
{"BMW","BMW","X4",54050},
{"BMW","BMW","X5",75400},
{"BMW","BMW","X7",77850},
{"Volkswagen","VW","Jetta",18995},
{"Volkswagen","VW","Passat",23995},
{"Volkswagen","VW","Arteon",36995},
{"Volkswagen","Audi","Q5",43500},
{"Volkswagen","Audi","Q3",38700},
{"Volkswagen","Audi","S6",72700},
{"Volkswagen","Audi","A6",55900},
{"Volkswagen","Porsche","Panamera",132760},
{"Volkswagen","Porsche","Macan",69480},
{"Volkswagen","Porsche","Cayenne",92960},
};

struct Car tempArray[30];
float afford=0.0;
float interest = 0.0;
int count = 0;
char *userinput  = argv[1];
int choice;
int choice2;
int  userNum = 0;
int downP = 0;
int size_of_array = sizeof(carArray)/sizeof(carArray[0]);
int tempsizeM =0;
char *tempM[10];
char *manf;


 userNum = atoi(userinput);
 printf("\nEnter Down Payment:\n");
 scanf("%d",&downP);
 afford = userNum*.15;
 if(userNum> 125000){
    interest = .0479;

 }
 else if (userNum <125000&& userNum> 80000){
    interest= .0655;
 }
 else if (userNum <80000&& userNum> 45000){
    interest= .0949;
 }
 else
 {
    interest = .1328;
 }

for(int i =0; i < size_of_array; i++){
    int is_duplicate = 0;
    for(int j = 0; j < tempsizeM; j++){
        if(carArray[i].Manufacturer== tempM[j]){
            is_duplicate =1;
            break;
        }
    }
    if(!is_duplicate&&afford> (affordableVehicle(carArray[i].price, downP, interest)*12)){
        tempM[tempsizeM] = carArray[i].Manufacturer;
        tempsizeM++;
    }
}
 

printf("Available Manufacturers:\n");
for (int i=0; i < tempsizeM;i++){
    int num=i +1;
    printf("%d)%s\t",num, tempM[i]);

}
printf("\nSelect Manufacture:");
scanf("%d", &choice);
manf =tempM[choice-1];
sortPrice(carArray,size_of_array);
printf("Available Make/Model:\n");
for (int i = 0; i < size_of_array; i++)
{  int num2 = i +1;
    if (strcmp(manf, carArray[i].Manufacturer) == 0&&afford> (affordableVehicle(carArray[i].price, downP, interest)*12))
    {    
        struct Car newCar = { copyString(carArray[i].Manufacturer),copyString(carArray[i].make), copyString(carArray[i].model), carArray[i].price };
        tempArray[count] = newCar;
        count++;

        float price = carArray[i].price;
        printf("%d) %s %s - $%.2f\n", count ,carArray[i].make,carArray[i].model,price);
    }
  
}

printf("Select Make/Model:");
scanf("%d", &choice2);

printf("You selected the %s %s. Your monthly payment is $%.2f.\n",tempArray[choice2-1].make,tempArray[choice2-1].model,affordableVehicle(tempArray[choice2-1].price, downP, interest));

return (0);
}