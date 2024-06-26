#include "../header.h"

using namespace std;

// MENU 7
//
// Function that deletes the user chosen listing
void deleteUserListing(Dealership& dealership) {
	int indexToChoose = 0;
	vector<int> searchedIndexes;

	// checker variable stores information whether the array is empty or not
	auto checker = searchedIndexes.begin();
	bool flag = false;

	vehicleType vehicleChoice = dealership.getChosenVehicleType();

	size_t listingsSize = dealership.getListingsSize(vehicleChoice);

	for (int i = 0; i < listingsSize; i++) {
		searchedIndexes.push_back(i);

		if (flag == false) {
			cout << "\n| Index |     Owner    |     Brand    |     Model    |  Price  |" << endl;
			cout << "----------------------------------------------------------------" << endl;
		}

		cout << "| " << i << right << setfill(' ') << setw(5 - to_string(i).size()) << "" << " | ";

		string ownerName = dealership.getOwnerNameWithIndex(dealership.getListingOwnerIndexWithIndex(vehicleChoice, i));
		cout << ownerName << right << setfill(' ') << setw(12 - ownerName.size()) << "" << " | ";

		string brand = dealership.getBrandWithIndex(vehicleChoice, i);
		cout << brand << right << setfill(' ') << setw(12 - brand.size()) << "" << " | ";

		string model = dealership.getModelWithIndex(vehicleChoice, i);
		cout << model << right << setfill(' ') << setw(12 - model.size()) << "" << " | ";

		int price = dealership.getListingPriceWithIndex(vehicleChoice, i);
		cout << price << right << setfill(' ') << setw(7 - to_string(price).size()) << "" << " |\n";

		flag = true;
	}

	if (flag == false) {
		cout << "\n" << setfill('=') << setw(68) << "=\n\n";
		cout << "    Array of listings is empty\n\n";
		cout << "    Press ENTER to go back to the menu\n";
		cout << "\n" << setfill('=') << setw(67) << "=\n";
		cin.ignore();
		cin.get();
	}
	else {
		do {
			cout << "\n    Enter a listing index to delete: ";
			cin >> indexToChoose;
			// Checker variable stores information whether the entered index has been previously searched and displayed
			checker = find(searchedIndexes.begin(), searchedIndexes.end(), indexToChoose);

			if (checker == searchedIndexes.end()) {
				cout << "\n    Chosen index doesn't exist";
				cout << "\n    Try again\n";
			}
			// Repeat until the correct index is entered
		} while (checker == searchedIndexes.end());

		string choice;

		do {
			cout << "\n" << setfill('=') << setw(68) << "=\n\n";
			cout << "    Are you sure you want to delete this listing?\n\n";
			cout << "    Enter [Y/N]\n";
			cout << "\n" << setfill('=') << setw(67) << "=\n";
			cin >> choice;

			if (choice != "Y" && choice != "N") {
				cout << "\n    You can choose only 'Y', or 'N'";
				cout << "\n    Try again\n";
			}
			// Repeat until the correct index is entered
		} while (choice != "Y" && choice != "N");

		if (choice == "Y") {
			dealership.deleteListing(vehicleChoice, indexToChoose);

			cout << "\n" << setfill('=') << setw(68) << "=\n\n";
			cout << "    Selected listing has been deleted\n\n";
			cout << "    Press ENTER to go back to the menu\n";
			cout << "\n" << setfill('=') << setw(67) << "=\n";
			cin.ignore();
			cin.get();
		}
	}
}