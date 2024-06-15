#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

class Appliance
{
public:
    string name;
    double usageRate;

    Appliance(const string &name, double usageRate) : name(name), usageRate(usageRate) {}
};

class ElectricityManagementSystem
{
private:
    const map<string, double> applianceUsage = {
        {"Fan", 75.0},
        {"Television", 150.0},
        {"DC Inverter", 300.0},
        {"Refrigerator", 150.0},
        {"Dc motor", 200.0},
        {"Bulb", 10.0},
        {"Computer", 100.0},
        {"Washing Machine", 500.0},
        {"Electric Stove", 1500.0},
        {"Oven", 1000.0},
    };
    double electricityCostPerUnit = 20.0;

    vector<pair<string, int>> applianceUsageData;
    int peakHours;
    int totalDailyUsage = 0;

public:
    void inputApplianceUsageData()
    {
        string appliance;
        int numAppliances;

        cout << "Available appliances:" << endl;
        cout << "_____________________" << endl;
        for (const auto &appliance : applianceUsage)
        {
            cout << "-> " << appliance.first << endl;
        }

        while (true)
        {
            cout << "_____________________" << endl;
            cout << "Enter the appliance you use (or 'done' to finish): ";
            getline(cin, appliance);
            if (appliance == "done")
            {
                break;
            }

            int hours;
            cout << "Enter the average number of hours for " << appliance << " per day: ";
            cin >> hours;
            cout << "Enter the number of " << appliance << " appliances you have: ";
            cin >> numAppliances;
            cin.ignore(); // Clear newline from input stream

            if (applianceUsage.find(appliance) != applianceUsage.end())
            {
                applianceUsageData.emplace_back(appliance, hours);
                totalDailyUsage += applianceUsage.at(appliance) * hours * numAppliances;
            }
        }
    }

    void inputPeakSunlightHours()
    {
        cout << "Enter the number of peak sunlight hours per day: ";
        cin >> peakHours;
    }

    double calculateMonthlyBillAndUnits(double &consumedUnits)
    {
        double totalUsage = 0.0;

        for (const auto &data : applianceUsageData)
        {
            const string &appliance = data.first;
            int hoursPerDay = data.second;

            if (applianceUsage.find(appliance) != applianceUsage.end())
            {
                totalUsage += (applianceUsage.at(appliance) * hoursPerDay * 30) / 1000; // Convert to kWh
            }
        }

        consumedUnits = totalUsage;
        return totalUsage * electricityCostPerUnit;
    }

    int calculateSolarPanels()
    {
        // Typical solar panel generates around 300W under optimal conditions
        // Assuming 5 hours of direct sunlight per day on average
        return ceil(totalDailyUsage / (300.0 * peakHours));
    }

    void run()
    {
        cout << "\n========================================================================================\n";
        cout << "                     Welcome to the Electricity Management System!" << endl;
        cout << "\n========================================================================================\n";

        inputApplianceUsageData();
        inputPeakSunlightHours();
        double consumedUnits;

        double monthlyBill = calculateMonthlyBillAndUnits(consumedUnits);
        cout << "Your estimated monthly electricity bill: PKR " << monthlyBill << endl;
        cout << "Total consumed units: " << consumedUnits << " kWh" << endl;

        int requiredSolarPanels = calculateSolarPanels();
        cout << "Number of solar panels needed: " << requiredSolarPanels << endl;

        string systemType;
        if (requiredSolarPanels >= 10)
        {
            systemType = "hybrid";
        }
        else if (requiredSolarPanels >= 5)
        {
            systemType = "off-grid";
        }
        else
        {
            systemType = "on-grid";
        }

        cout << "Recommended electricity system for your house: " << systemType << " system" << endl;
        cout << "\t_______________________________________________\n" << endl;
        cout << "\tThanks for Using Electricity Management System!" << endl;
        cout << "\t_______________________________________________\n" << endl;
    }

    void provideEnergyEfficiencyRecommendations()
    {
        cout << "\nEnergy Efficiency Recommendations:\n";
        cout << "_________________________________\n";
        cout << "1. Consider using energy-efficient appliances.\n";
        cout << "2. Unplug electronics when not in use.\n";
        cout << "3. Set your thermostat to an optimal temperature.\n";
        cout << "4. Use LED bulbs for lighting.\n";
        // Add more recommendations here

        cout << "\n";
    }

    void customizeElectricityCost()
    {
        cout << "Enter the new electricity cost per unit: ";
        cin >> electricityCostPerUnit;
        cout << "Electricity cost per unit updated to: " << electricityCostPerUnit << " PKR\n";
    }

    void customizeApplianceList()
    {
        applianceUsageData.clear();
        totalDailyUsage = 0;

        cout << "\nCustomize Appliance List:\n";
        cout << "_________________________\n";

        for (const auto &appliance : applianceUsage)
        {
            string response;
            cout << "Add " << appliance.first << " to your appliance list? (yes/no): ";
            cin >> response;

            if (response == "yes")
            {
                int hours, numAppliances;
                cout << "Enter the average number of hours for " << appliance.first << " per day: ";
                cin >> hours;
                cout << "Enter the number of " << appliance.first << " appliances you have: ";
                cin >> numAppliances;
                cin.ignore(); // Clear newline from input stream

                applianceUsageData.emplace_back(appliance.first, hours);
                totalDailyUsage += appliance.second * hours * numAppliances;
            }
            cout << "Appliance list updated!\n";
        }

        
    }
};

int main()
{
    ElectricityManagementSystem ems;

    while (true)
    {
        system("cls"); // Clear the console before displaying the menu

        cout << "\n========================================================================================\n";
        cout << "                     Welcome to the Extended Electricity Management System!" << endl;
        cout << "\n========================================================================================\n";
        cout << "1. Run the Electricity Management System\n";
        cout << "2. Provide Energy Efficiency Recommendations\n";
        cout << "3. Customize Appliance List\n";
        cout << "4. Customize Electricity Cost\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        int option;
        cin >> option;
        cin.ignore(); // Clear newline from input stream

        switch (option)
        {
        case 1:
            ems.run();
            break;
        case 2:
            ems.provideEnergyEfficiencyRecommendations();
            break;
        case 3:
            ems.customizeApplianceList();
            break;
        case 4:
            ems.customizeElectricityCost();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please select a valid option.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.get(); // Wait for user input before clearing the screen
    }

    return 0;
}
