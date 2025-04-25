#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 120

typedef struct {
    char name[30];
    char symbol[5];
    int atomicNumber;
    int protons;
    int neutrons;
    float atomicMass;
    char category[30];
    char stateAtRoomTemp[20];
} Element;

char *questions[120][2] = {
    {"What is the symbol for Hydrogen?", "H"},
 {"What is the symbol for Oxygen?", "O"},
 {"What is the atomic number of Helium?", "2"},
 {"What element has the symbol 'C'?", "Carbon"},
 {"What is the symbol for Nitrogen?", "N"},
 {"What is the symbol for Gold?", "Au"},
 {"What is the atomic number of Lithium?", "3"},
 {"What is the symbol for Sodium?", "Na"},
 {"What element has the symbol 'Mg'?", "Magnesium"},
 {"What is the atomic number of Fluorine?", "9"},
 {"What is the symbol for Potassium?", "K"},
 {"What is the symbol for Iron?", "Fe"},
 {"What is the atomic number of Neon?", "10"},
 {"What element has the symbol 'Al'?", "Aluminium"},
 {"What is the atomic number of Chlorine?", "17"},
 {"What is the symbol for Silver?", "Ag"},
 {"What is the atomic number of Phosphorus?", "15"},
 {"What element has the symbol 'Si'?", "Silicon"},
 {"What is the symbol for Calcium?", "Ca"},
 {"What is the atomic number of Sulfur?", "16"},
 {"What is the state of matter of Mercury at room temperature?", "Liquid"},
 {"Which group does Helium belong to?", "Noble gases"},
 {"What is the atomic number of Argon?", "18"},
 {"What is the symbol for Bromine?", "Br"},
 {"What is the atomic number of Nickel?", "28"},
 {"What element has the symbol 'Pb'?", "Lead"},
 {"What is the category of Sodium?", "Alkali metal"},
 {"What is the atomic number of Boron?", "5"},
 {"What is the state of matter of Oxygen at room temperature?", "Gas"},
 {"What is the symbol for Chromium?", "Cr"},
 {"What is the symbol for Zinc?", "Zn"},
 {"What element has the symbol 'Co'?", "Cobalt"},
 {"What is the atomic number of Beryllium?", "4"},
 {"What is the category of Neon?", "Noble gas"},
 {"What is the atomic number of Iodine?", "53"},
 {"What element has the symbol 'Se'?", "Selenium"},
 {"What is the atomic number of Krypton?", "36"},
 {"What is the symbol for Cadmium?", "Cd"},
 {"What element has the symbol 'Sb'?", "Antimony"},
 {"What is the atomic number of Xenon?", "54"},
 {"What is the category of Gold?", "Transition metal"},
 {"What is the atomic number of Radon?", "86"},
 {"What is the symbol for Uranium?", "U"},
 {"Which element has the symbol 'Fr'?", "Francium"},
 {"What is the atomic number of Polonium?", "84"},
 {"What is the symbol for Thorium?", "Th"},
 {"What is the atomic number of Actinium?", "89"},
 {"What is the symbol for Neptunium?", "Np"},
 {"What element has the symbol 'Pu'?", "Plutonium"},
 {"What is the atomic number of Californium?", "98"},
 {"What is the category of Helium?", "Noble gas"},
 {"What is the symbol for Einsteinium?", "Es"},
 {"What element has the symbol 'Fm'?", "Fermium"},
 {"What is the atomic number of Mendelevium?", "101"},
 {"What is the symbol for Nobelium?", "No"},
 {"What element has the symbol 'Lr'?", "Lawrencium"},
 {"What is the atomic number of Rutherfordium?", "104"},
 {"What is the symbol for Dubnium?", "Db"},
 {"What element has the symbol 'Sg'?", "Seaborgium"},
 {"What is the atomic number of Bohrium?", "107"},
 {"What is the symbol for Hassium?", "Hs"},
 {"What element has the symbol 'Mt'?", "Meitnerium"},
 {"What is the atomic number of Darmstadtium?", "110"},
 {"What is the symbol for Roentgenium?", "Rg"},
 {"What element has the symbol 'Cn'?", "Copernicium"},
 {"What is the atomic number of Nihonium?", "113"},
 {"What is the symbol for Flerovium?", "Fl"},
 {"What element has the symbol 'Mc'?", "Moscovium"},
 {"What is the atomic number of Livermorium?", "116"},
 {"What is the symbol for Tennessine?", "Ts"},
 {"What element has the symbol 'Og'?", "Oganesson"},
 {"Which element has the highest atomic number?", "Oganesson"},
 {"What is the most abundant element in the Earth's crust?", "Oxygen"},
 {"What is the lightest element?", "Hydrogen"},
 {"Which element is known as the 'King of Chemicals'?", "Sulfuric acid"},
 {"Which element is commonly used in batteries?", "Lithium"},
 {"What is the primary gas found in the sun?", "Hydrogen"},
 {"Which element is used in balloons to make them float?", "Helium"},
 {"Which element is the best conductor of electricity?", "Silver"},
 {"What is the most abundant metal in the Earth's crust?", "Aluminium"},
 {"Which element is known as 'Quicksilver'?", "Mercury"},
 {"What is the atomic mass of Carbon?", "12.011"},
 {"What is the atomic mass of Nitrogen?", "14.007"},
 {"Which element is a liquid at room temperature besides Mercury?", "Bromine"},
 {"What is the melting point of Tungsten?", "3422"},
 {"What element is used as a filament in light bulbs?", "Tungsten"},
 {"What is the atomic mass of Oxygen?", "15.999"},
 {"Which element has the highest melting point?", "Tungsten"},
 {"Which element is used in making semiconductors?", "Silicon"},
 {"What is the atomic mass of Sodium?", "22.990"},
 {"What is the boiling point of Helium?", "-268.93"},
 {"Which element is used to disinfect water?", "Chlorine"},
 {"Which element is used in thermometers?", "Mercury"},
 {"Which noble gas is used in advertising signs?", "Neon"},
 {"Which element is used in the treatment of cancer?", "Radium"},
 {"Which element is known as 'Fool's Gold'?", "Iron pyrite"},
 {"Which element is used in making fertilizers?", "Phosphorus"},
 {"Which element is used in the manufacture of aircraft?", "Titanium"},
 {"What is the atomic mass of Magnesium?", "24.305"},
 {"Which element is used as a catalyst in the hydrogenation of oils?", "Nickel"},
 {"What is the atomic mass of Aluminum?", "26.982"},
 {"Which element is used in the production of glass?", "Silica"},
 {"What is the atomic mass of Silicon?", "28.085"},
 {"Which element is a key component in steel production?", "Iron"},
 {"What is the atomic mass of Phosphorus?", "30.974"},
 {"Which element is used in fireworks to produce green colors?", "Barium"},
 {"Which element is found in the center of hemoglobin?", "Iron"},
 {"Which element is the main component of bones?", "Calcium"},
 {"What is the atomic mass of Sulfur?", "32.06"},
 {"Which element is used to make dental fillings?", "Mercury"},
 {"Which element is used in the production of photographic film?", "Silver"},
 {"What is the atomic mass of Chlorine?", "35.45"},
 {"Which element is used in the manufacture of matches?", "Phosphorus"},
 {"Which element is used in the manufacture of batteries?", "Lead"},
 {"Which element is known as 'Nature's Building Block'?", "Carbon"},
 {"What is the atomic mass of Argon?", "39.948"},
 {"Which element is used in the making of jewelry?", "Gold"},
 {"What is the atomic mass of Potassium?", "39.098"},
 {"Which element is used in making pencil leads?", "Graphite"},
 };

void displayTable(Element elements[], int count);
void searchElement(Element elements[], int count);
void testQuiz();
int loadElements(Element elements[]);

int main() {
    Element elements[MAX_ELEMENTS];
    int elementCount = loadElements(elements);

    if (elementCount == 0) {
        printf("Error: No elements loaded. Ensure 'periodic_table_data.txt' exists.\n");
        return 1;
    }

    int choice;
    do {
        printf("\n--- Periodic Table Management System ---\n");
        printf("1. Display Table\n");
        printf("2. Search by Element\n");
        printf("3. Test Quiz\n");
        printf("4. Add New Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTable(elements, elementCount);
                break;
            case 2:
                searchElement(elements, elementCount);
                break;
            case 3:
                testQuiz();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


int loadElements(Element elements[]) {
    FILE *file = fopen("periodic_table_data.txt", "r");
    if (!file) {
        printf("Error: Could not open file 'periodic_table_data.txt'.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %f %s %s", 
                  elements[count].name, 
                  elements[count].symbol, 
                  &elements[count].atomicNumber, 
                  &elements[count].protons, 
                  &elements[count].neutrons, 
                  &elements[count].atomicMass, 
                  elements[count].category, 
                  elements[count].stateAtRoomTemp) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}


void displayTable(Element elements[], int count) {
    printf("\n--- Periodic Table ---\n");
    printf("\n");
    printf("H                                                                   He\n");
    printf("Li  Be                                          B   C   N   O   F   Ne\n");
    printf("Na  Mg                                          Al  Si  P   S   Cl  Ar\n");
    printf("K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr\n");
    printf("Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe\n");
    printf("Cs  Ba  La  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn\n");
    printf("Fr  Ra  Ac  Rf  Db  Sg  Bh  Hs  Mt  Ds  Rg  Cn  Nh  Fl  Mc  Lv  Ts  Og\n");
    printf("\n");
    printf("            *  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu\n");
    printf("            ** Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm  Md  No  Lr\n");
    printf("\n");
    printf("* Lanthanides\n");
    printf("** Actinides\n");
}


void searchElement(Element elements[], int count) {
    int searchType;
    char query[30];
    printf("\nSearch by:\n1. Name\n2. Symbol\nEnter your choice: ");
    scanf("%d", &searchType);

    printf("Enter search query: ");
    scanf("%s", query);

    for (int i = 0; i < count; i++) {
        if ((searchType == 1 && strcasecmp(elements[i].name, query) == 0) ||
            (searchType == 2 && strcasecmp(elements[i].symbol, query) == 0)) {

            printf("\nElement Found:\n");
            printf("Name: %s\n", elements[i].name);
            printf("Symbol: %s\n", elements[i].symbol);
            printf("Atomic Number: %d\n", elements[i].atomicNumber);
            printf("Protons: %d\n", elements[i].protons);
            printf("Neutrons: %d\n", elements[i].neutrons);
            printf("Atomic Mass: %.2f\n", elements[i].atomicMass);
            printf("Category: %s\n", elements[i].category);
            printf("State at Room Temperature: %s\n", elements[i].stateAtRoomTemp);
            return;
        }
    }

    printf("No element found for the given query.\n");
}

void testQuiz() {
  
    int numQuestions = 5; 
    int totalQuestions = 120; 
    int score = 0;

    printf("\n--- Test Quiz ---\n");
    srand(time(0));

    for (int i = 0; i < numQuestions; i++) {
        int qIndex = rand() % totalQuestions;
        char answer[30];
        printf("\nQ%d: %s ", i + 1, questions[qIndex][0]);
        scanf("%s", answer);

        if (strcasecmp(answer, questions[qIndex][1]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong. Correct Answer: %s\n", questions[qIndex][1]);
        }
    }

    printf("\nQuiz Over! Your Score: %d/%d\n", score, numQuestions);
}


