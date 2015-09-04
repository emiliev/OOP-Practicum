#include <iostream>
#include <fstream>
#include <string.h>

const int kNameLength = 23;
const int kAllCars = 4;
const int kLamborginiHp = 670;
const int kMercedesHp = 503;
const int kPaganiHp = 740;
const int kBugattiHp = 1020;
const int kMinRegNumber = 999;
const int kMaxRegNumber = 9999;


struct Person{
    char owner[kNameLength];
    int uniqueID;
    int registerNumber;

};

struct Car{

    char model[kNameLength];
    int uniqueNumber;
    int horsepower;

};


void loadCars(Car cars[]){
    strcpy(cars[0].model, "Lambordgini Murcielago");
    cars[0].uniqueNumber = 0;
    cars[0].horsepower = kLamborginiHp;

    strcpy(cars[1].model, "Mercedes-AMG");
    cars[1].uniqueNumber = 1;
    cars[1].horsepower = kMercedesHp;

    strcpy(cars[2].model, "Pagani Zonda R");
    cars[2].uniqueNumber = 2;
    cars[2].horsepower = kPaganiHp;

    strcpy(cars[3].model, "Bugatti Veyron");
    cars[3].uniqueNumber = 3;
    cars[3].horsepower = kBugattiHp;
}

//returns the size of the .dat file
int numberOfOwners(){

    std::ifstream outputFile("db-save.dat", std::ios::binary);
    if(!outputFile){
        std::cerr<<"Error!File still does not exists\n";
        return 0;
    }
    std::streampos ending;
    outputFile.seekg(0,std::ios::end);
    int structSize = outputFile.tellg();

    outputFile.close();
    return structSize / sizeof(struct Person);
}

//makes new person instance
void newRecord(Person* human, int length){

    std::ofstream outputFile("db-save.dat", std::ios::binary | std::ios::app);
    if(!outputFile){
        std::cerr<<"Error!\n";
    }
    else{

        int uniqueCarID;
        int carRegisterNumber;
        do{
            std::cout<<"Enter unique car Id( between 0 and 3): ";
            std::cin>>uniqueCarID;
            std::cout<<"Enter car register number (four digit number): ";
            std::cin>>carRegisterNumber;
        }while(!((uniqueCarID >= 0 && uniqueCarID < kAllCars) &&(carRegisterNumber > kMinRegNumber && carRegisterNumber <= kMaxRegNumber)));
        char personName[kNameLength];
        std::cin.ignore();
        std::cout<<"Enter owner's name: ";
        std::cin.getline(personName,kNameLength);

        bool different = true;
        for(int index =  0; index < length; ++index){
            if(human[index].registerNumber == carRegisterNumber){
                different = false;
                break;
            }
        }

        if(different){
            Person person;
            strcpy(person.owner,personName);
            person.registerNumber = carRegisterNumber;
            person.uniqueID = uniqueCarID;

            outputFile.write((char*) &person, sizeof(struct Person));
            outputFile.close();
        }
        else{
            std::cerr<<"Error! Current registry number is unavailable!\n";
        }
    }
}

//resizing the dinamicaly allocated array of persons
void resizeArray(Person* person,int length){

     Person* resize_person  = new Person[length + 1];
     for(int index = 0; index < length; ++index){
        resize_person[index] = person[index];
     }

     person = resize_person;
     delete [] resize_person;
}

//load data from binary and prints it in the console
void loadDataFromBinary(Person* person, int length){

    std::ifstream output("db-save.dat", std::ios::binary);

    for(int index = 0; index < length; ++index){
        output.read((char*) &person[index], sizeof(struct Person));
        std::cout<<"Owner: "<<person[index].owner<<"\t Car ID: "<<person[index].uniqueID
       <<"\t register number: "<<person[index].registerNumber<<std::endl;
    }
    output.close();
}

//counts the number of cars of each kind
void carTable(int* countArray, Person* p, int length){

    for(int index = 0; index < length; ++index){
        countArray[p[index].uniqueID] +=1;
    }
}

//returns the index of the most popular car
int mostPopularCar(int* countArray, int length){
    int digit = 0;
    for(int index = 0; index < length; ++index){
        if(countArray[digit] < countArray[index]){
            digit = index;
        }
    }

    return digit;
}

//calculates the average horse power
int averagePower(int* countArray, Car* cars, int length){
    int numberOfCars = 0;
    int sum = 0;
    for(int index = 0; index < length; ++index){
        sum +=(countArray[index] * cars[index].horsepower);
        numberOfCars += countArray[index];
    }

    return sum / numberOfCars;
}

//generates the .txt file and writes in it
 void generateText(int ownersNumber,Person* person,Car* cars, int* countArray){

    std::ofstream input("car-report.txt");

    int popularCarIndex = mostPopularCar(countArray,kAllCars);
    int averageHorsePower = averagePower(countArray,cars,kAllCars);

    input<<"Most popular car: "<<cars[popularCarIndex].model<<std::endl;
    input<<"Average horse power: "<<averageHorsePower<<std::endl;

    for(int pass  = 0; pass < numberOfOwners(); ++pass ){
        int sum = 0;
        bool isInFile = false;
        for(int index = 0; index < numberOfOwners(); ++index){

            if(strcmp(person[index].owner, person[pass].owner) == 0){
                sum += cars[person[index].uniqueID].horsepower;
                if(index < pass){
                    isInFile = true;
                    break;
                }
            }
        }
        if(!isInFile){
            input<<"Name: "<<person[pass].owner<<"  horse power of cars: "<<sum<<std::endl;
        }
    }
    input.close();
 }

int main()
{
    Car cars[kAllCars];
    loadCars(cars);
    int arrayLength = numberOfOwners();
    int countArray[kAllCars] = {0,};
    Person* person = new Person[arrayLength];
    bool isRunning = true;
    while(isRunning){

        std::cout<<"\n1.Enter new record.\n2.Load Data.\n3.Generate car report.\n4.Close program.\n";

        int choice;
        std::cout<<"\nEnter choice: ";
        std::cin>>choice;

        switch(choice){

        case 1:

            newRecord(person,numberOfOwners());
            break;
        case 2:

            int newLength;
            newLength = numberOfOwners();
            std::cout<<newLength<<"\t"<<arrayLength<<std::endl;
            if(arrayLength < newLength){
                resizeArray(person,newLength);
            }
            loadDataFromBinary(person,newLength);
            break;
        case 3:

            carTable(countArray,person,newLength);
            generateText(numberOfOwners(),person,cars,countArray);

            break;
        default:
            isRunning = false;
            break;
        }
    }

    return 0;
}
