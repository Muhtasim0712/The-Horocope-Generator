#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for user details
struct User {
    char name[50];
    int day, month, year;
    char zodiac_sign[20];
    char element[10];
    char quality[10];
};

typedef struct User Astrologer;

// Zodiac signs, traits, and horoscopes
const char *z_signs[]={
    "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
    "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"
};

const char *z_traits[]={
    "Disciplined and Responsible.",
    "Innovative and Independent.",
    "Compassionate and Artistic.",
    "Courageous and Determined.",
    "Reliable and Patient.",
    "Curious and Adaptable.",
    "Sensitive and Emotional.",
    "Charismatic and Confident.",
    "Analytical and Practical.",
    "Diplomatic and Fair-minded.",
    "Resourceful and Passionate.",
    "Optimistic and Adventurous."
};

const char *daily_horoscope[]={
    "Focus on practical goals today.",
    "Try something creative this afternoon.",
    "Spend time reflecting on emotions.",
    "Take charge of a new challenge.",
    "Be patient with others today.",
    "Explore new ideas or projects.",
    "Focus on family and emotional connections.",
    "Step into the spotlight with confidence.",
    "Organize your tasks for efficiency.",
    "Strive for harmony in relationships.",
    "Uncover hidden opportunities today.",
    "Take a leap of faith in a new direction."
};

const char *weekly_horoscope[]={
    "This week, focus on setting long-term goals and staying grounded.",
    "Expect some unexpected changes this week that may lead to new ideas.",
    "This is a week for self-reflection, deepen your emotional connections.",
    "Challenges may come your way, but your courage will help you overcome them.",
    "Stay patient, as steady progress will bring rewards in the long run.",
    "This week, explore creative ideas and new possibilities.",
    "Take time for family and home life this week, as it will bring you peace.",
    "Shine brightly this week; your confidence will inspire others.",
    "This is a good week to organize and focus on getting things done.",
    "Strive for balance in all aspects of your life this week.",
    "Look out for hidden opportunities this week, which may lead to growth.",
    "This week, take risks and embrace adventure in all forms."
};

const char *yearly_horoscope[]={
    "Capricorn: A year of growth and discipline awaits you.",
    "Aquarius: Embrace innovation and personal freedom this year.",
    "Pisces: Expect deep emotional connections and creativity.",
    "Aries: Bold moves will define your year.",
    "Taurus: Steady progress and reliability will bring success.",
    "Gemini: Communication and adaptability will lead to new opportunities.",
    "Cancer: Prioritize emotional well-being and family.",
    "Leo: Shine bright and inspire others.",
    "Virgo: Focus on perfecting your skills.",
    "Libra: Strive for balance and harmony in all areas.",
    "Scorpio: Transformation and passion will define this year.",
    "Sagittarius: Adventure and learning await you."
};

const char *stone[]={
    "Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl",
    "Ruby", "Peridot", "Sapphire", "Opal", "Topaz", "Turquoise"
};

const char *lucky_colors[]={
    "Brown, Gray, Black",
    "Blue, Gray, Black",
    "Sea Green, Lavender",
    "Red, White",
    "Green, Pink",
    "Yellow, Green",
    "White, Silver",
    "Gold, Orange",
    "Gray, Beige",
    "Pink, Blue",
    "Maroon, Red",
    "Purple, Red"
};

// Elements and qualities associated with zodiac signs
const char *elements[]={
    "Earth", "Air", "Water", "Fire"
};

const char *qualities[]={
    "Cardinal", "Fixed", "Mutable"
};

// Function to determine the zodiac sign based on the date
const char *find_z_sign(int day, int month) {
    if ((month == 1 && day <= 19) || (month == 12 && day >= 22)) return z_signs[0];
    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) return z_signs[1];
    if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) return z_signs[2];
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) return z_signs[3];
    if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) return z_signs[4];
    if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) return z_signs[5];
    if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) return z_signs[6];
    if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) return z_signs[7];
    if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) return z_signs[8];
    if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) return z_signs[9];
    if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) return z_signs[10];
    if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) return z_signs[11];
    return "Unknown";
}

// Function to determine the element and quality based on the zodiac sign
void find_element_quality(const char *zodiac, char *element, char *quality) {
    int index = z_index(zodiac);
    if (index >= 0) {
        strcpy(element, elements[index % 4]);
        strcpy(quality, qualities[index % 3]);
    } else {
        strcpy(element, "Unknown");
        strcpy(quality, "Unknown");
    }
}

// Function to find the index of the zodiac sign
int z_index(const char *zodiac) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(zodiac, z_signs[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to generate daily horoscope for any given day
/*void generateHoroscopeForAnyDay(int day, int month) {
    const char *zodiacSign = find_z_sign(day, month);
    int index = z_index(zodiacSign);
    if (index != -1) {
        printf("\nZodiac Sign for %02d/%02d is %s.\n", day, month, zodiacSign);
        printf("Personality Traits: %s\n", z_traits[index]);
        printf("Daily Horoscope: %s\n", daily_horoscope[index]);
    } else {
        printf("Invalid date provided. Please enter a valid day and month.\n");
    }
} */

// Function to generate daily horoscope

// Compatibility matrix (12x12) for zodiac signs, single-digit scale (1 to 9)
const int compatibility_matrix[12][12] = {
    // Capricorn, Aquarius, Pisces, Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius
    {9, 7, 6, 4, 8, 5, 8, 7, 9, 6, 9, 8}, // Capricorn
    {7, 9, 7, 5, 6, 8, 4, 6, 5, 7, 5, 9}, // Aquarius
    {6, 7, 9, 6, 4, 6, 8, 5, 7, 8, 7, 6}, // Pisces
    {4, 5, 6, 9, 6, 7, 4, 9, 5, 6, 5, 8}, // Aries
    {8, 6, 4, 6, 9, 5, 8, 6, 9, 7, 8, 6}, // Taurus
    {5, 8, 6, 7, 5, 9, 6, 7, 4, 9, 6, 8}, // Gemini
    {8, 4, 8, 4, 8, 6, 9, 6, 8, 5, 9, 7}, // Cancer
    {7, 6, 5, 9, 6, 7, 6, 9, 5, 7, 5, 8}, // Leo
    {9, 5, 7, 5, 9, 4, 8, 5, 9, 6, 8, 6}, // Virgo
    {6, 7, 8, 6, 7, 9, 5, 7, 6, 9, 6, 8}, // Libra
    {9, 5, 7, 5, 8, 6, 9, 5, 8, 6, 9, 5}, // Scorpio
    {8, 9, 6, 8, 6, 8, 7, 8, 6, 8, 5, 9}  // Sagittarius
};

void check_compatibility(const char *zodiac1, const char *zodiac2) {
    int index1 = z_index(zodiac1);
    int index2 = z_index(zodiac2);

    if (index1 != -1 && index2 != -1) {
        int score = compatibility_matrix[index1][index2];
        printf("\nCompatibility between %s and %s: Score = %d (on a scale of 1 to 9)\n", zodiac1, zodiac2, score);

        // Provide an interpretation of the compatibility score
        if (score >= 8) {
            printf("Great match! These signs have a strong connection and harmony.\n");
        } else if (score >= 5) {
            printf("Good match! These signs can build a meaningful relationship with effort.\n");
        } else {
            printf("Challenging match! These signs may require more understanding and compromise.\n");
        }
    } else {
        printf("Invalid zodiac signs provided.\n");
    }
}

void find_daily_horoscope(Astrologer user) {
    int index = z_index(user.zodiac_sign);
    printf("\nHello %s! Your zodiac sign is %s.\n", user.name, user.zodiac_sign);
    printf("Personality Traits: %s\n", z_traits[index]);
    printf("Today's Horoscope: %s\n", daily_horoscope[index]);
}

// Function to generate weekly horoscope
void find_weekly_horoscope(Astrologer user) {
    int index = z_index(user.zodiac_sign);
    printf("\nHello %s! Your zodiac sign is %s.\n", user.name, user.zodiac_sign);
    printf("Personality Traits: %s\n", z_traits[index]);
    printf("\nWeekly Horoscope for %s:\n%s\n", user.zodiac_sign, weekly_horoscope[index]);
}
// Function to generate monthly horoscope
void find_monthly_horoscope(const char *zodiac, const char *month) {
    char filename[50];
    snprintf(filename, sizeof(filename), "%s.txt", zodiac); // Create the filename (e.g., "Capricorn.txt")

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Could not open file for %s\n", zodiac);
        return;
    }

    char buffer[100];
    int found = 0;

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fptr)) {
        // Check if the line contains the specified month
        if (strstr(buffer, month) != NULL) {
            printf("\nHoroscope for %s (%s) \n", month, zodiac);
            found = 1;

            // Print lines until the next month's horoscope or end of file
            while (fgets(buffer, sizeof(buffer), fptr)) {
                if (buffer[0] == '\n' || strstr(buffer, "January") || strstr(buffer, "February") ||
                    strstr(buffer, "March") || strstr(buffer, "April") || strstr(buffer, "May") ||
                    strstr(buffer, "June") || strstr(buffer, "July") || strstr(buffer, "August") ||
                    strstr(buffer, "September") || strstr(buffer, "October") || strstr(buffer, "November") ||
                    strstr(buffer, "December")) {
                    break; // Stop when the next month's section is found
                }
                printf("%s", buffer);
            }
            break;
        }
    }

    if (!found) {
        printf("No horoscope found for %s in %s\n", month, zodiac);
    }

    fclose(fptr); // Close the file
}

// Function to generate yearly horoscope
void find_yearly_horoscope(Astrologer user) {
    int index = z_index(user.zodiac_sign);
    printf("\nHello %s! Your zodiac sign is %s.\n", user.name, user.zodiac_sign);
    printf("Personality Traits: %s\n", z_traits[index]);
    printf("\nYearly Horoscope for %s:\n%s\n", user.zodiac_sign, yearly_horoscope[index]);
}

// Function to sum digits of a number recursively
int sum_digits(int num) {//Sum of digits
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum > 9 ? sum_digits(sum) : sum;
}

// Function to calculate life path number
int path_number(int day, int month, int year) {
    return sum_digits(day) + sum_digits(month) + sum_digits(year);
}

// Function to display life path number
void display_path(Astrologer user) {
    int path_num = path_number(user.day, user.month, user.year);
    printf("\nYour Life Path Number is: %d\n", path_num);
    printf("Life Path Traits: ");
    switch (path_num) {
        case 1: printf("Leader, Independent, Ambitious.\n"); break;
        case 2: printf("Diplomatic, Peaceful, Intuitive.\n"); break;
        case 3: printf("Creative, Expressive, Optimistic.\n"); break;
        case 4: printf("Practical, Disciplined, Organized.\n"); break;
        case 5: printf("Adventurous, Freedom-loving, Dynamic.\n"); break;
        case 6: printf("Responsible, Caring, Harmonious.\n"); break;
        case 7: printf("Analytical, Introspective, Wise.\n"); break;
        case 8: printf("Powerful, Ambitious, Determined.\n"); break;
        case 9: printf("Compassionate, Idealistic, Generous.\n"); break;
        default: printf("Unique and adaptable.\n");
    }
}

// Function to display birthstone and lucky color
void lucky_details(Astrologer user) {
    int index = z_index(user.zodiac_sign);
    printf("\nLucky Details for %s:\n", user.zodiac_sign);
    printf("Birthstone: %s\n", stone[index]);
    printf("Lucky Colors: %s\n", lucky_colors[index]);
}

// Function to show astrological events
void astro_event() {
    printf("\nUpcoming Astrological Events:\n");
    printf("January: Mercury Retrograde begins.\n");
    printf("March: Full Moon in Virgo.\n");
    printf("June: Summer Solstice.\n");
    printf("August: Blue Moon.\n");
    printf("November: Lunar Eclipse in Taurus.\n");
}

// Function to find user by name
Astrologer *find_user(Astrologer *users, int userCount, const char *name, int day, int month, int year) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0 && users[i].day == day && users[i].month == month && users[i].year == year) {
            return &users[i];
        }
    }
    return NULL;
}

// Function to check for duplicate user
int check_duplicate(Astrologer *users, int userCount, const char *name, int day, int month, int year) {
    for (int i = 0; i < userCount; i++) {
        // Check if the name matches
        if (strcmp(users[i].name, name) == 0) {
            // Check if the birthdate matches
            if (users[i].day == day && users[i].month == month && users[i].year == year) {
                return 2;  // Duplicate found with same name and birthdate
            }
            else
                return 1;
        }
    }
    return 0;  // No duplicate found
}

// Function to save users to a file
void save_users(Astrologer users[], int userCount) {
    FILE *fptr = fopen("users.txt", "w");
    if (fptr == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(fptr, "%s,%d,%d,%d,%s,%s,%s\n",
                users[i].name, users[i].day, users[i].month, users[i].year,
                users[i].zodiac_sign, users[i].element, users[i].quality);
    }

    fclose(fptr);
    printf("Users have been saved successfully.\n");
}

// Function to load users from a file
int load_users(Astrologer users[], int *userCount) {
    FILE *fptr = fopen("users.txt", "r");
    if (fptr == NULL) {
        printf("Unable to open file for reading.\n");
        return;
    }

    *userCount = 0;
    while (fscanf(fptr, "%49[^,],%d,%d,%d,%19[^,],%9[^,],%9[^\n]\n",
                  users[*userCount].name, &users[*userCount].day, &users[*userCount].month, &users[*userCount].year,
                  users[*userCount].zodiac_sign, users[*userCount].element, users[*userCount].quality) == 7) {
        (*userCount)++;
    }

    fclose(fptr);
    return 1;
}

// Function to add a new user
void add_user(Astrologer users[], int *userCount) {
    Astrologer new_user;

    printf("\nEnter name: ");
    fgets(new_user.name, sizeof(new_user.name), stdin);
    new_user.name[strcspn(new_user.name, "\n")] = '\0';

    int valid_date = 0;
    while (!valid_date) {
        printf("Enter birthdate (dd mm yyyy): ");
        scanf("%d %d %d", &new_user.day, &new_user.month, &new_user.year);

        if (is_valid_date(new_user.day, new_user.month, new_user.year)) {
            valid_date = 1; // Date is valid
        } else {
            printf("Invalid date. Please try again.\n");
        }
    }

    strcpy(new_user.zodiac_sign, find_z_sign(new_user.day, new_user.month));
    find_element_quality(new_user.zodiac_sign, new_user.element, new_user.quality);

    int duplicate_check = check_duplicate(users, *userCount, new_user.name, new_user.day, new_user.month, new_user.year);
    if (duplicate_check ==  2) {
        printf("A user with this name and birthdate already exists. No need to add a new user.\n");
        return;
    } else if (duplicate_check == 1) {
        printf("Duplicate user found of the same name.\n");
        int confirm_day, confirm_month, confirm_year;
        printf("Enter the birthdate again to confirm (dd mm yyyy): ");
        scanf("%d %d %d", &confirm_day, &confirm_month, &confirm_year);
        new_user.day=confirm_day;
        new_user.month=confirm_month;
        new_user.year=confirm_year;
    }
// If no duplicates found, add the new user
    users[*userCount] = new_user;
    (*userCount)++;
    printf("User  added successfully!\n");
}


int is_valid_date(int day, int month, int year) {
    if(year <=2025 && year >0){

        if(year ==2025)
        {
            if( month==1 && day<=30 ) return 1;
            else
                return 0;
        }

        if (month < 1 || month > 12) return 0; // Invalid month
        if (day < 1) return 0; // Invalid day

        // Days in each month (non-leap year)
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year and update February's days
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month[1] = 29;
        }

        if (day > days_in_month[month - 1]) return 0;// Day exceeds max days in the month


        return 1; // Valid date
    }
    else
        return 0;
}



int main() {
    Astrologer users[500];
    int count_user = 0;

    // Load users from file at the beginning
    if (load_users(users, &count_user)) {
        printf("\n\t\t\t\t\t\t\t\t==============================\n");
        printf("\t\t\t\t\t\t\t\t     The Horoscope Generator  \n");
        printf("\t\t\t\t\t\t\t\t==============================\n");
        printf("Users have been loaded successfully.Now we can start.\n");
    } else {
        printf("No users loaded.\n");
    }
    //Function to display menu and handle user choices

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add New User\n");
        printf("2. Access User by Name and Birthdate\n");
        printf("3. Show Astrological Events\n");
        printf("4. Check Compatibility Between Two Users\n");
        printf("5. Generate Daily Horoscope\n");
        printf("6. Generate Weekly Horoscope\n");
        printf("7. Generate Monthly Horoscope\n");
        printf("8. Generate Yearly Horoscope\n");
        printf("9. Display Birthstone and Lucky Colors\n");
        printf("10. Display Life Path Number\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear buffer

        switch (choice) {
            case 1:
                add_user(users, &count_user);
                break;
            case 2:
                {
                    char name[50];
                    int day,month,year;
                    printf("Enter name: ");
                    fgets(name,sizeof(name),stdin);
                    name[strcspn(name, "\n")] = '\0';
                    printf("Enter birthdate (dd mm yyyy): ");
                    scanf("%d %d %d", &day, &month, &year);
                    Astrologer *user = find_user(users, count_user, name, day, month, year);

                    if (user != NULL) {
                        printf("\nUser found: %s\n", user->name);
                        printf("Birthdate: %02d/%02d/%d\n", user->day, user->month, user->year);
                        printf("Zodiac Sign: %s\n", user->zodiac_sign);
                        printf("Element: %s\n", user->element);
                        printf("Quality: %s\n", user->quality);
                    } else {
                        printf("No user found with the name %s and the specified birthdate\n", name);
                    }
                }
                break;
            case 3:
                astro_event();
                break;
            /*case 4:
                {
                    int day, month;
                    printf("Enter date (dd mm): ");
                    scanf("%d %d", &day, &month);
                    generateHoroscopeForAnyDay(day, month);
                }
                break; */
            case 4: {
                    char name1[50], name2[50];
                     int day,month,year;

                    // Get names of the two users
                    printf("\nEnter the name of the first person: ");
                    fgets(name1, sizeof(name1), stdin);
                    name1[strcspn(name1, "\n")] = '\0';  // Remove trailing newline
                    printf("Enter birthdate (dd mm yyyy): ");
                    scanf("%d %d %d", &day, &month, &year);
                    Astrologer *user1 = find_user(users, count_user, name1,day,month,year);

                    printf("Enter the name of the second person: ");
                    fgets(name2, sizeof(name2), stdin);
                    name2[strcspn(name2, "\n")] = '\0';  // Remove trailing newline
                    printf("Enter birthdate (dd mm yyyy): ");
                    scanf("%d %d %d", &day, &month, &year);
                    Astrologer *user2 = find_user(users, count_user, name1,day,month,year);

                    // Find the two users by name



                    if (user1 != NULL && user2 != NULL) {
                    // Call the compatibility check function with the zodiac signs
                    check_compatibility(user1->zodiac_sign, user2->zodiac_sign);
                    }
                    else {
                        printf("One or both users were not found. Please ensure the names are correct.\n");
                        }
                    break;
                    }

            case 5:
                {
                    char name[50];
                    int day,month,year;
                    printf("Enter name: ");
                    fgets(name,sizeof(name),stdin);
                    name[strcspn(name, "\n")] = '\0';
                    printf("Enter birthdate (dd mm yyyy): ");
                    scanf("%d %d %d", &day, &month, &year);
                    Astrologer *user = find_user(users, count_user, name,day,month,year);
                    if (user != NULL) {
                        find_daily_horoscope(*user);
                    } else {
                        printf("No user found with the name %s.\n", name);
                    }
                }
                break;
            case 6:
                {
                char name[50];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int day, month, year;
                printf("Enter birthdate (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                Astrologer *user = find_user(users, count_user, name, day, month, year);
                if (user != NULL) {
                    find_weekly_horoscope(*user);
                } else {
                    printf("No user found with the name %s and the specified birthdate.\n", name);
                }
            }
                break;
            case 7:
                {
                    char name[50], month[20];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int day, month_num, year;
                printf("Enter birthdate (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month_num, &year);
                Astrologer *user = find_user(users, count_user, name, day, month_num, year);
                if (user != NULL) {
                    printf("Enter the month you want to read (e.g., January): ");
                    scanf("%19s", month);
                    find_monthly_horoscope(user->zodiac_sign, month);
                } else {
                    printf("No user found with the name %s and the specified birthdate.\n", name);
                }
                }
                break;
            case 8:
                {
                    char name[50];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int day, month, year;
                printf("Enter birthdate (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                Astrologer *user = find_user(users, count_user, name, day, month, year);
                if (user != NULL) {
                    find_yearly_horoscope(*user);
                } else {
                    printf("No user found with the name %s and the specified birthdate.\n", name);
                }
                }
                break;
            case 9:
                {
                    char name[50];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int day, month, year;
                printf("Enter birthdate (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                Astrologer *user = find_user(users, count_user, name, day, month, year);
                if (user != NULL) {
                    lucky_details(*user);
                } else {
                    printf("No user found with the name %s and the specified birthdate.\n", name);
                }
                }
                break;
            case 10:
                {
                     char name[50];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int day, month, year;
                printf("Enter birthdate (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                Astrologer *user = find_user(users, count_user, name, day, month, year);
                if (user != NULL) {
                    display_path(*user);
                } else {
                    printf("No user found with the name %s and the specified birthdate.\n", name);
                }
                }
                break;
            case 0:
                save_users(users, count_user);
                printf("Exiting. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;

}
