#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Appliance {
private:
    string name;
    double power;
    double activeHour;

public:
    Appliance(string name, double power, double activeHour) {
        this->name = name;
        this->power = power;
        this->activeHour = activeHour;
    }

    double calculateMonthlyUsage() const {
        return (power * activeHour) / 1000.0;
    }

    string getName() const {
        return name;
    }
};

const int SOLAR_PANEL_CAPACITY = 250;  // Capacity of a single solar panel in watts
const int BATTERY_CAPACITY_PER_KWH = 100;  // Battery capacity required per kilowatt-hour

float calculate_battery_capacity(float load, float autonomy) {
    float batterySize = load * autonomy + ((load * autonomy) * 20) / 100;
    return batterySize;
}

int calculate_solar_panels(float load, float sunshine_hours) {
    float total_energy_required = load * 30;  // Assuming 30 days in a month
    int solar_panels = static_cast<int>(total_energy_required / SOLAR_PANEL_CAPACITY);
    if (solar_panels < 1) {
        solar_panels = 1;  // Set the minimum number of solar panels to 1
    }
    return solar_panels;
}


float calculate_money_saved(float load, float sunshine_hours, float electricity_rate) {
    float energy_generated = SOLAR_PANEL_CAPACITY * sunshine_hours * 30;  // Assuming 30 days in a month
    float energy_consumed = load * 30;  // Assuming 30 days in a month
    float energy_savings = energy_generated - energy_consumed;
    float money_saved = energy_savings * electricity_rate;
    return money_saved;
}



int main() {
    vector<Appliance> appliances;
    int numAppliances;

    cout << "Enter the number of appliances: ";
    cin >> numAppliances;

    cout << "Available Appliances:\n";
    cout << "1. Bulb\n";
    cout << "2. Tube Light\n";
    cout << "3. Ceiling Fan\n";
    cout << "4. Fridge 165 Litre\n";
    cout << "5. Freezer\n";
    cout << "6. Mixie\n";
    cout << "7. Washing Machine\n";
    cout << "8. Iron, Water Pump, Vacuum Cleaner\n";
    cout << "9. Motor – 1 horsepower\n";
    cout << "10. Television\n";
    cout << "11. Tape Recorder\n";
    cout << "12. Video Player\n";
    cout << "13. Microwave\n";
    cout << "14. Computer with LCD\n";
    cout << "15. Computer with Monitor\n";
    cout << "16. Laptop Charging\n";
    cout << "17. Scanner\n";
    cout << "18. Mobile Charger\n";

    for (int i = 0; i < numAppliances; ++i) {
        int choice;
        double activeHours;

        cout << "Enter the number corresponding to the appliance " << i + 1 << ": ";
        cin >> choice;

        string name;
        double power;

        switch (choice) {
            case 1:
                name = "Bulb";
                power = 60;
                break;
            case 2:
                name = "Tube Light";
                power = 40;
                break;
            case 3:
                name = "Ceiling Fan";
                power = 60;
                break;
            case 4:
                name = "Fridge 165 Litre";
                power = 100;
                break;
            case 5:
                name = "Freezer";
                power = 225;
                break;
            case 6:
                name = "Mixie";
                power = 450;
                break;
            case 7:
                name = "Washing Machine";
                power = 325;
                break;
            case 8:
                name = "Iron, Water Pump, Vacuum Cleaner";
                power = 750;
                break;
            case 9:
                name = "Motor – 1 horsepower";
                power = 1000;
                break;
            case 10:
                name = "Television";
                power = 100;
                break;
            case 11:
                name = "Tape Recorder";
                power = 20;
                break;
            case 12:
                name = "Video Player";
                power = 40;
                break;
            case 13:
                name = "Microwave";
                power = 900;
                break;
            case 14:
                name = "Computer with LCD";
                power = 80;
                break;
            case 15:
                name = "Computer with Monitor";
                power = 120;
                break;
            case 16:
                name = "Laptop Charging";
                power = 100;
                break;
            case 17:
                name = "Scanner";
                power = 10;
                break;
            case 18:
                name = "Mobile Charger";
                power = 5;
                break;
            default:
                cout << "Invalid choice. Setting power to 0.\n";
                name = "Unknown Appliance";
                power = 0;
                break;
        }

        cout << "Enter the active hours of " << name << " per day: ";
        cin >> activeHours;

        appliances.push_back(Appliance(name, power, activeHours));
    }

    double totalUsage = 0.0;

    for (const Appliance& appliance : appliances) {
        totalUsage += appliance.calculateMonthlyUsage();
    }

    cout << "\nMonthly Electricity Usage per Appliance:\n";

    for (const Appliance& appliance : appliances) {
        cout << appliance.getName() << ": " << appliance.calculateMonthlyUsage() << " kWh\n";
    }

    cout << "\nTotal Monthly Electricity Usage: " << totalUsage << " kWh\n";

    float monthly_load = totalUsage;
    float sunshine_hours;
    float autonomy;
    float electricity_rate = 0.25; // $
    int system_type;

    if (monthly_load < 5.0) {
        system_type = 1;  // Set system type to on-grid if monthly load is less than 5 kWh
    } else {
        // Getting user input
        cout << "Enter the average daily sunshine hours: ";
        cin >> sunshine_hours;
        cout << "Enter the desired autonomy in days: ";
        cin >> autonomy;

        // Selecting system type
        cout << "\nSelect the system type:" << endl;
        cout << "1. On-grid system" << endl;
        cout << "2. Off-grid system" << endl;
        cout << "3. Hybrid system" << endl;
        cout << "Enter your choice: ";
        cin >> system_type;
    }

    // Calculate based on system type
    switch (system_type) {
        case 1: {  // On-grid system
            int solar_panels = calculate_solar_panels(monthly_load, sunshine_hours);
            float money_saved = calculate_money_saved(monthly_load, sunshine_hours, electricity_rate);
            cout << "\nOn-grid System" << endl;
            cout << "Solar panels required: " << solar_panels << endl;
            cout << "Money saved per year: $" << fixed << setprecision(3) << money_saved << " American" << endl;
            break;
        }
        case 2: {  // Off-grid system
            float battery_capacity = calculate_battery_capacity(monthly_load, autonomy);
            int solar_panels = calculate_solar_panels(monthly_load, sunshine_hours);
            cout << "\nOff-grid System" << endl;
            cout << "Battery capacity required: " << battery_capacity << " kWh" << endl;
            cout << "Solar panels required: " << solar_panels << endl;
            break;
        }
        case 3: {  // Hybrid system
            float battery_capacity = calculate_battery_capacity(monthly_load, autonomy);
            int solar_panels = calculate_solar_panels(monthly_load, sunshine_hours);
            cout << "\nHybrid System" << endl;
            cout << "Battery capacity required: " << battery_capacity << " kWh" << endl;
            cout << "Solar panels required: " << solar_panels << endl;
            break;
        }
        default:
            cout << "Invalid system type selected." << endl;
            break;
    }

    return 0;
}