#include <iostream>
#include <cmath>
using namespace std;

class SolarSystem 
{
private:
    double panelCapacity;
    double gridEfficiency;
    double batteryEfficiency;
    double onGridThreshold;
    double hybridThreshold;
    double batteryCapacity;
    double chargingCurrent;
    double dischargingCurrent;

public:
    SolarSystem(double panelCapacity, double gridEfficiency, double batteryEfficiency,
                double onGridThreshold, double hybridThreshold,
                double batteryCapacity, double chargingCurrent, double dischargingCurrent)
        : panelCapacity(panelCapacity), gridEfficiency(gridEfficiency), batteryEfficiency(batteryEfficiency),
          onGridThreshold(onGridThreshold), hybridThreshold(hybridThreshold),
          batteryCapacity(batteryCapacity), chargingCurrent(chargingCurrent), dischargingCurrent(dischargingCurrent) {}

    enum class SolarSystemType 
	{
        Invalid,
        OnGrid,
        Hybrid,
        OffGrid
    };

    SolarSystemType recommendSystem(double load) 
	{
        if (load <= 0) 
		{
            return SolarSystemType::Invalid;
        } else if (load <= onGridThreshold) 
		{
            return SolarSystemType::OnGrid;
        } else if (load <= hybridThreshold) 
		{
            return SolarSystemType::Hybrid;
        } else {
            return SolarSystemType::OffGrid;
        }
    }

    int calculatePanels(double load, SolarSystemType systemType) 
	{
        double panelsRequired = 0;

        switch (systemType) 
		{
            case SolarSystemType::OnGrid:
                panelsRequired = ceil(load / (panelCapacity * gridEfficiency));
                break;
            case SolarSystemType::Hybrid:
                panelsRequired = ceil(load / (panelCapacity * batteryEfficiency));
                break;
            case SolarSystemType::OffGrid:
                panelsRequired = ceil(load / panelCapacity);
                break;
            default:
                break;
        }

        return static_cast<int>(panelsRequired);
    }


    void printSystemDetails(double sentinelLoad) 
	{
        SolarSystemType recommendedSystem = recommendSystem(sentinelLoad);

        if (recommendedSystem != SolarSystemType::Invalid) 
		{
            cout << "Recommended System: ";
            switch (recommendedSystem) 
			{
                case SolarSystemType::OnGrid:
                    cout << "On-Grid";
                    break;
                case SolarSystemType::Hybrid:
                    cout << "Hybrid";
                    break;
                case SolarSystemType::OffGrid:
                    cout << "Off-Grid";
                    break;
                default:
                    break;
            }
            cout << endl;

            int panelsRequired = calculatePanels(sentinelLoad, recommendedSystem);
            cout << "Number of panels required: " << panelsRequired << endl;

            double totalCapacity = panelsRequired * panelCapacity;
            double co2Saved = totalCapacity * 0.5;

            cout << "Total capacity: " << totalCapacity << " watts" << endl;
            cout << "Estimated CO2 saved: " << co2Saved << " kg" << endl;

            if (recommendedSystem == SolarSystemType::Hybrid) 
			{
                double batteryTime = batteryCapacity / dischargingCurrent;
                double chargingTime = batteryCapacity / chargingCurrent;
                cout << "\n-----------------------------------------" << endl;
                cout << "Additional Features for Hybrid System:" << endl;
                cout << "-----------------------------------------\n" << endl;
                cout << "Battery capacity: " << batteryCapacity << " watt-hours" << endl;
                cout << "Battery discharging time: " << batteryTime << " hours" << endl;
                cout << "Battery charging time: " << chargingTime << " hours" << endl;

                // Calculate the number of batteries needed
                int batteriesRequired = ceil(batteryCapacity / batteryEfficiency / panelCapacity);
                cout << "Number of batteries required: " << batteriesRequired << endl;
            }
        }
		 else 
		{
            cout << "Invalid input. Please enter a valid load." << endl;
        }
    }
};

int main() 
{
    double panelCapacity = 320.0;
    double gridEfficiency = 0.85;
    double batteryEfficiency = 0.85;
    double onGridThreshold = 3000.0;
    double hybridThreshold = 7000;
    double batteryCapacity = 15000.0;
    double chargingCurrent = 40.0;
    double dischargingCurrent = 80.0;

    SolarSystem solarSystem(panelCapacity, gridEfficiency, batteryEfficiency,
                            onGridThreshold, hybridThreshold,
                            batteryCapacity, chargingCurrent, dischargingCurrent);

    double sentinelLoad;
    cout << "\n\t\t\t\t====================================================\n" << endl;
    cout << "\t\t\t\t\tWelcome to Electricity Management System" << endl;
    cout << "\n\t\t\t\t====================================================\n" << endl;
    
    cout << "Enter your sentinel load (in watts): ";
    cin >> sentinelLoad;
    cout<<endl;
    cout << "-----------------------------------------" << endl;
    cout << "\tSolar System Recommendation" << endl;
    cout << "-----------------------------------------" << endl;
    cout<<endl;

    solarSystem.printSystemDetails(sentinelLoad);
    cout<<endl;
     system ("pause");  
    return 0;
}

