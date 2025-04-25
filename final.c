#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int MAX_ELEMENTS = 118;
const int MAX_QUESTIONS = 120;
const int NUM_QUESTIONS = 5;

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


void display_table(GtkWidget *widget, gpointer data);
void search_element(GtkWidget *widget, gpointer data);
void test_quiz(GtkWidget *widget, gpointer data);
void quit_program(GtkWidget *widget, gpointer data);
int load_elements(Element elements[]);


void test_quiz(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Test Quiz", NULL, GTK_DIALOG_MODAL, "Start", GTK_RESPONSE_ACCEPT, "Close", GTK_RESPONSE_CLOSE, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label = gtk_label_new("Select Difficulty Level:");
    gtk_container_add(GTK_CONTAINER(content_area), label);
    GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Level 1");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Level 2");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Level 3");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Level 4");
 
    gtk_container_add(GTK_CONTAINER(content_area), combo);
    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        const gchar *level = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo));
        int start, end;
        if (g_strcmp0(level, "Level 1") == 0) {
            start = 0;
            end = 40;
        } else if (g_strcmp0(level, "Level 2") == 0) {
            start = 30;
            end = 80;
        } else {
            start = 0;
            end = 120;
        }
        int score = 0;
        srand(time(0));
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            int qIndex = start + (rand() % (end - start));
            GtkWidget *q_dialog = gtk_dialog_new_with_buttons("Question", NULL, GTK_DIALOG_MODAL, "Submit", GTK_RESPONSE_ACCEPT, NULL);
            GtkWidget *q_content_area = gtk_dialog_get_content_area(GTK_DIALOG(q_dialog));
            GtkWidget *q_label = gtk_label_new(questions[qIndex][0]);
            GtkWidget *entry = gtk_entry_new();
            gtk_container_add(GTK_CONTAINER(q_content_area), q_label);
            gtk_container_add(GTK_CONTAINER(q_content_area), entry);
            gtk_widget_show_all(q_dialog);
            gint q_response = gtk_dialog_run(GTK_DIALOG(q_dialog));
            if (q_response == GTK_RESPONSE_ACCEPT) {
                const char *answer = gtk_entry_get_text(GTK_ENTRY(entry));
                if (strcasecmp(answer, questions[qIndex][1]) == 0) {
                    score++;
                }
            }
            gtk_widget_destroy(q_dialog);
        }
        char score_message[50];
        sprintf(score_message, "Quiz Over! Your Score: %d/%d", score, NUM_QUESTIONS);
        GtkWidget *score_dialog = gtk_dialog_new_with_buttons("Score", NULL, GTK_DIALOG_MODAL, "OK", GTK_RESPONSE_OK, NULL);
        GtkWidget *score_content_area = gtk_dialog_get_content_area(GTK_DIALOG(score_dialog));
        GtkWidget *score_label = gtk_label_new(score_message);
        gtk_container_add(GTK_CONTAINER(score_content_area), score_label);
        gtk_widget_show_all(score_dialog);
        gtk_dialog_run(GTK_DIALOG(score_dialog));
        gtk_widget_destroy(score_dialog);
    }
    gtk_widget_destroy(dialog);
}
void display_table(GtkWidget *widget, gpointer data) {
    Element *elements = (Element *)data;
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Periodic Table", NULL,GTK_DIALOG_MODAL, "Close",  GTK_RESPONSE_CLOSE, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(content_area), grid);
    const char *table_layout[10][18] = {
        {"H", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "He"},
        {"Li", "Be", "", "", "", "", "", "", "", "", "", "", "B", "C", "N", "O", "F", "Ne"},
        {"Na", "Mg", "", "", "", "", "", "", "", "", "", "", "Al", "Si", "P", "S", "Cl", "Ar"},
        {"K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr"},
        {"Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"},
        {"Cs", "Ba", "La*", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"},
        {"Fr", "Ra", "Ac*", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"},
        {"", "", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu"},
        {"", "", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"}
    };
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 18; col++) {
            if (table_layout[row][col] && strlen(table_layout[row][col]) > 0) {
                GtkWidget *button = gtk_button_new_with_label(table_layout[row][col]);
                gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            }
        }
    }
    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
void search_element(GtkWidget *widget, gpointer data) {
    Element *elements = (Element *)data;
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Search Element", NULL,GTK_DIALOG_MODAL, "Search", GTK_RESPONSE_ACCEPT, "Cancel", GTK_RESPONSE_REJECT, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), entry);
    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        const char *query = gtk_entry_get_text(GTK_ENTRY(entry));
        gboolean found = FALSE;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (strcasecmp(elements[i].name, query) == 0 || strcasecmp(elements[i].symbol, query) == 0) {
                found = TRUE;
                GtkWidget *result_dialog = gtk_dialog_new_with_buttons("Element Found", NULL, GTK_DIALOG_MODAL, "OK", GTK_RESPONSE_OK, NULL);
                GtkWidget *result_content_area = gtk_dialog_get_content_area(GTK_DIALOG(result_dialog));
                char details[512];
                sprintf(details, 
                        "Name: %s\n"  
                        "Symbol: %s\n" 
                        "Atomic Number: %d\n"
                        "Protons: %d\n"
                        "Neutrons: %d\n"
                        "Atomic Mass: %.2f\n"
                        "Category: %s\n"
                        "State at Room Temperature: %s\n", 
                        elements[i].name, elements[i].symbol, elements[i].atomicNumber, 
                        elements[i].protons, elements[i].neutrons, elements[i].atomicMass, 
                        elements[i].category, elements[i].stateAtRoomTemp);
                
                GtkWidget *label = gtk_label_new(details);
                gtk_container_add(GTK_CONTAINER(result_content_area), label);

                gtk_widget_show_all(result_dialog);
                gtk_dialog_run(GTK_DIALOG(result_dialog));
                gtk_widget_destroy(result_dialog);
                break;
            }
        }

        if (!found) {
            GtkWidget *not_found_dialog = gtk_dialog_new_with_buttons("Element Not Found", NULL, GTK_DIALOG_MODAL, "ok", GTK_RESPONSE_OK, NULL);
            GtkWidget *not_found_content_area = gtk_dialog_get_content_area(GTK_DIALOG(not_found_dialog));
            GtkWidget *label = gtk_label_new("No matching element found.");
            gtk_container_add(GTK_CONTAINER(not_found_content_area), label);
            gtk_widget_show_all(not_found_dialog);
            gtk_dialog_run(GTK_DIALOG(not_found_dialog));
            gtk_widget_destroy(not_found_dialog);
        }
    }

    gtk_widget_destroy(dialog);
}

void quit_program(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int load_elements(Element elements[]) {
    FILE *file = fopen("d:/cse 2-1/project/periodic_table_data.txt", "r");
    if (!file) {
        printf("Could not open file!\n");
        return 0;
    }
    int count;
    for(count = 0;count <= MAX_ELEMENTS ; count++)
    {
        fscanf(file, "%29s %4s %d %d %d %f %29s %19s",
                          elements[count].name,
                          elements[count].symbol,
                          &elements[count].atomicNumber,
                          &elements[count].protons,
                          &elements[count].neutrons,
                          &elements[count].atomicMass,
                          elements[count].category,
                          elements[count].stateAtRoomTemp);
    }
    fclose(file);
    return count;
}

int main() {
    
    gtk_init(NULL,NULL);

    Element elements[MAX_ELEMENTS];
    int element_count = load_elements(elements);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Periodic Table Management");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(quit_program), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *display_btn = gtk_button_new_with_label("Display Table");
    GtkWidget *search_btn = gtk_button_new_with_label("Search Element");
    GtkWidget *quiz_btn = gtk_button_new_with_label("Test Quiz");
    GtkWidget *quit_btn = gtk_button_new_with_label("Quit Program");

    g_signal_connect(display_btn, "clicked", G_CALLBACK(display_table), elements);
    g_signal_connect(search_btn, "clicked", G_CALLBACK(search_element), elements);
    g_signal_connect(quiz_btn, "clicked", G_CALLBACK(test_quiz), elements);
    g_signal_connect(quit_btn, "clicked", G_CALLBACK(quit_program), NULL);

    gtk_box_pack_start(GTK_BOX(vbox), display_btn, 1, 1, 0);
    gtk_box_pack_start(GTK_BOX(vbox), search_btn, 1, 1, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quiz_btn, 1, 1, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quit_btn, 1, 1, 0);

    gtk_widget_show_all(window);

    gtk_main();
    
    return 0;
}
