#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <limits>

using namespace std;

class TnGEWallet
{
private:
    double walletBalance;
    string currentUser;
    vector<string> paymentHistory;
    map<string, double> feeStructure;

    int totalTransactions;

public:
    TnGEWallet(string userName) : currentUser(userName), walletBalance(0.0), totalTransactions(0)
    {

        feeStructure["toll"] = 0.0;
        feeStructure["parking"] = 0.0;
        feeStructure["fuel"] = 0.0;
        feeStructure["food"] = 0.0;
        feeStructure["transport"] = 0.0;
        feeStructure["investment"] = 2.50;
        feeStructure["insurance"] = 5.00;
    }

    void displayWelcomeScreen()
    {
        cout << "\n================================================================\n";
        cout << "         Welcome to TnG eWallet Evolution Simulator           \n";
        cout << "    Demonstrating Malaysia's Fintech Disruption (1997-2025)    \n";
        cout << "================================================================\n";
        cout << "User: " << currentUser << "\n";
        cout << "Current Balance: RM " << fixed << setprecision(2) << walletBalance << "\n";
        cout << "Total Transactions: " << totalTransactions << "\n";
        cout << "================================================================\n";
    }

    double getValidAmount(const string &promptMessage)
    {
        double inputAmount;
        while (true)
        {
            cout << promptMessage;
            cin >> inputAmount;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR: Please enter a valid number!\n";
                continue;
            }

            if (inputAmount <= 0)
            {
                cout << "ERROR: Amount must be greater than RM 0.00!\n";
                continue;
            }

            return inputAmount;
        }
    }

    void performTopUp()
    {
        cout << "\n--- Balance Top Up Service ---\n";
        cout << "Available top-up methods: Online Banking, Credit Card, Cash Deposit\n";

        double topUpAmount = getValidAmount("Enter amount to top up (RM): ");

        cout << "\nProcessing top up...\n";
        walletBalance += topUpAmount;
        totalTransactions++;

        string transactionRecord = "TOP UP: +RM " + to_string(topUpAmount) +
                                   " | Balance: RM " + to_string(walletBalance);
        paymentHistory.push_back(transactionRecord);

        cout << "\n✓ TOP UP SUCCESSFUL!\n";
        cout << "Amount Added: RM " << fixed << setprecision(2) << topUpAmount << "\n";
        cout << "New Balance: RM " << walletBalance << "\n";
        cout << "Transaction ID: TXN" << (1000 + totalTransactions) << "\n";
    }

    void processPayment()
    {
        cout << "\n--- TnG eWallet Payment Services ---\n";
        cout << "Evolution-based Services Available:\n";
        cout << "1. Toll Payment         [Since 1997 - Core Service]\n";
        cout << "2. Parking Payment      [Since 2002 - SmartTAG Era]\n";
        cout << "3. Fuel Payment         [Since 2007 - Expansion Phase]\n";
        cout << "4. Food & Beverage      [Since 2017 - Mobile App Era]\n";
        cout << "5. Public Transport     [Since 2012 - RFID Integration]\n";
        cout << "6. Investment Products  [Since 2022 - Fintech Platform] *Fee: RM 2.50\n";
        cout << "7. Insurance Services   [Since 2022 - Complete Solution] *Fee: RM 5.00\n";
        cout << "\nSelect payment service (1-7): ";

        int serviceChoice;
        cin >> serviceChoice;

        if (cin.fail() || serviceChoice < 1 || serviceChoice > 7)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: Invalid service selection! Please choose 1-7.\n";
            return;
        }

        string selectedService;
        string serviceCategory;

        switch (serviceChoice)
        {
        case 1:
            selectedService = "Toll Payment";
            serviceCategory = "toll";
            break;
        case 2:
            selectedService = "Parking Payment";
            serviceCategory = "parking";
            break;
        case 3:
            selectedService = "Fuel Payment";
            serviceCategory = "fuel";
            break;
        case 4:
            selectedService = "Food & Beverage";
            serviceCategory = "food";
            break;
        case 5:
            selectedService = "Public Transport";
            serviceCategory = "transport";
            break;
        case 6:
            selectedService = "Investment Products";
            serviceCategory = "investment";
            break;
        case 7:
            selectedService = "Insurance Services";
            serviceCategory = "insurance";
            break;
        }

        double paymentAmount = getValidAmount("Enter payment amount (RM): ");
        double serviceFee = feeStructure[serviceCategory];
        double totalDeduction = paymentAmount + serviceFee;

        if (walletBalance < totalDeduction)
        {
            cout << "\nPAYMENT FAILED - INSUFFICIENT BALANCE!\n";
            cout << "Required Amount: RM " << fixed << setprecision(2) << totalDeduction << "\n";
            cout << "Available Balance: RM " << walletBalance << "\n";
            cout << "Shortfall: RM " << (totalDeduction - walletBalance) << "\n";
            cout << "Please top up your wallet first.\n";
            return;
        }

        walletBalance -= totalDeduction;
        totalTransactions++;

        string paymentRecord = selectedService + ": -RM " + to_string(paymentAmount);
        if (serviceFee > 0)
        {
            paymentRecord += " (Fee: RM " + to_string(serviceFee) + ")";
        }
        paymentRecord += " | Balance: RM " + to_string(walletBalance);
        paymentHistory.push_back(paymentRecord);

        cout << "\n✓ PAYMENT SUCCESSFUL!\n";
        cout << "Service: " << selectedService << "\n";
        cout << "Payment Amount: RM " << fixed << setprecision(2) << paymentAmount << "\n";
        if (serviceFee > 0)
        {
            cout << "Service Fee: RM " << serviceFee << "\n";
            cout << "Total Deducted: RM " << totalDeduction << "\n";
        }
        cout << "Remaining Balance: RM " << walletBalance << "\n";
        cout << "Transaction ID: TXN" << (1000 + totalTransactions) << "\n";
    }

    void displayAccountSummary()
    {
        cout << "\n--- TnG eWallet Account Summary ---\n";
        cout << "Account Holder: " << currentUser << "\n";
        cout << "Current Balance: RM " << fixed << setprecision(2) << walletBalance << "\n";
        cout << "Total Transactions: " << totalTransactions << "\n";
        cout << "Account Status: " << (walletBalance > 0 ? "Active" : "Requires Top Up") << "\n";

        if (walletBalance < 10.0)
        {
            cout << "\n  LOW BALANCE WARNING: Consider topping up for seamless transactions.\n";
        }
        else if (walletBalance > 500.0)
        {
            cout << "\n HIGH BALANCE TIP: Consider investment products for potential returns.\n";
        }
    }

    void displayTransactionHistory()
    {
        cout << "\n--- Complete Transaction History ---\n";
        cout << "Account: " << currentUser << "\n";
        cout << "================================================================\n";

        if (paymentHistory.empty())
        {
            cout << "No transactions recorded yet.\n";
            cout << "Start by topping up your wallet or making a payment.\n";
        }
        else
        {
            cout << "Showing " << paymentHistory.size() << " transaction(s):\n\n";
            for (size_t transactionIndex = 0; transactionIndex < paymentHistory.size(); transactionIndex++)
            {
                cout << "[" << (transactionIndex + 1) << "] " << paymentHistory[transactionIndex] << "\n";
            }

            cout << "\n--- Summary ---\n";
            cout << "Total Transactions: " << totalTransactions << "\n";
            cout << "Current Balance: RM " << fixed << setprecision(2) << walletBalance << "\n";
        }
        cout << "================================================================\n";
    }

    void displayEvolutionTimeline()
    {
        cout << "\n================================================================\n";
        cout << "    TnG eWallet Evolution Timeline - Malaysia's Fintech Story   \n";
        cout << "     (Connecting to Disruptive Innovation Analysis - Part 1)     \n";
        cout << "================================================================\n";
        cout << "1997: Touch 'n Go Card Era\n";
        cout << "   • Physical card for toll payments only\n";
        cout << "   • 1 million users | Manual reload required\n";
        cout << "   • Disruption Level: Basic digitization of toll collection\n\n";

        cout << "2002: SmartTAG Integration\n";
        cout << "   • RFID technology for faster lane access\n";
        cout << "   • 2.5 million users | Extended to parking\n";
        cout << "   • Disruption Level: Convenience enhancement\n\n";

        cout << "2007: Government Services Expansion\n";
        cout << "   • Integration with government-linked services\n";
        cout << "   • 4 million users | Beyond transport sector\n";
        cout << "   • Disruption Level: Cross-sector adoption\n\n";

        cout << "2012: RFID Experimentation\n";
        cout << "   • Contactless payment trials\n";
        cout << "   • 6 million users | Retail partnerships\n";
        cout << "   • Disruption Level: Retail payment disruption begins\n\n";

        cout << "2017: Mobile App Revolution (CRITICAL DISRUPTION POINT)\n";
        cout << "   • Fully digital wallet launched\n";
        cout << "   • 8 million users | Cashless ecosystem\n";
        cout << "   • Disruption Level: Traditional banking threatened\n\n";

        cout << "2022: Complete Fintech Platform\n";
        cout << "   • Investment products + Insurance services\n";
        cout << "   • Multi-million users | Super-app model\n";
        cout << "   • Disruption Level: Comprehensive financial services\n\n";

        cout << "2025: Projected Future (25 million users)\n";
        cout << "   • AI-powered financial services\n";
        cout << "   • Complete ecosystem integration\n";
        cout << "   • Disruption Level: Traditional banking obsolescence\n";
        cout << "================================================================\n";

        cout << "\n DISRUPTION ANALYSIS INSIGHT:\n";
        cout << "This evolution demonstrates Clayton Christensen's Disruptive\n";
        cout << "Innovation model - starting as simple toll payment (low-end\n";
        cout << "disruption) and evolving to challenge traditional banking\n";
        cout << "(mainstream market disruption).\n";
    }

    void displayWalletAnalytics()
    {
        cout << "\n--- Wallet Usage Analytics ---\n";
        cout << "User Engagement Score: ";
        if (totalTransactions >= 10)
            cout << "High Active User \n";
        else if (totalTransactions >= 5)
            cout << "Regular User \n";
        else
            cout << "New User \n";

        cout << "Balance Management: ";
        if (walletBalance > 100)
            cout << "Excellent \n";
        else if (walletBalance > 20)
            cout << "Good \n";
        else
            cout << "Needs Attention \n";

        cout << "Recommended Next Action: ";
        if (walletBalance < 10)
            cout << "Top up wallet\n";
        else if (totalTransactions < 3)
            cout << "Try different payment services\n";
        else
            cout << "Explore investment/insurance products\n";
    }
};

int getValidMenuChoice(int minimumChoice, int maximumChoice)
{
    int userChoice;
    while (true)
    {
        cin >> userChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: Please enter a valid number between "
                 << minimumChoice << " and " << maximumChoice << ": ";
            continue;
        }

        if (userChoice < minimumChoice || userChoice > maximumChoice)
        {
            cout << "ERROR: Please select a number between "
                 << minimumChoice << " and " << maximumChoice << ": ";
            continue;
        }

        return userChoice;
    }
}

int main()
{

    cout << "================================================================\n";
    cout << "        TnG eWallet Evolution Simulator - Malaysia 2024        \n";
    cout << "================================================================\n";
    cout << "This program demonstrates the digital transformation journey\n";
    cout << "of Touch 'n Go from 1997 physical cards to 2025 super-app.\n";
    cout << "Perfect case study for Disruptive Innovation analysis!\n";
    cout << "================================================================\n\n";

    string userName;
    cout << "Enter your full name to create TnG eWallet account: ";
    getline(cin, userName);

    while (userName.empty() || userName.find_first_not_of(' ') == string::npos)
    {
        cout << "ERROR: Name cannot be empty. Please enter your name: ";
        getline(cin, userName);
    }

    TnGEWallet userWallet(userName);
    int menuChoice;

    do
    {
        userWallet.displayWelcomeScreen();
        cout << "\n--- TnG eWallet Main Menu ---\n";
        cout << "1. Top Up Wallet Balance\n";
        cout << "2. Make Payment (Multiple Services)\n";
        cout << "3. View Account Summary\n";
        cout << "4. Transaction History\n";
        cout << "5. Wallet Analytics\n";
        cout << "6. Evolution Timeline (Educational)\n";
        cout << "7. Exit Application\n";
        cout << "\nSelect your choice (1-7): ";

        menuChoice = getValidMenuChoice(1, 7);

        try
        {
            switch (menuChoice)
            {
            case 1:
                userWallet.performTopUp();
                break;
            case 2:
                userWallet.processPayment();
                break;
            case 3:
                userWallet.displayAccountSummary();
                break;
            case 4:
                userWallet.displayTransactionHistory();
                break;
            case 5:
                userWallet.displayWalletAnalytics();
                break;
            case 6:
                userWallet.displayEvolutionTimeline();
                break;
            case 7:
                cout << "\n================================================================\n";
                cout << "Thank you for using TnG eWallet Evolution Simulator!\n";
                cout << "You've experienced Malaysia's fintech journey from 1997-2025.\n";
                cout << "This simulation connects directly to disruptive innovation\n";
                cout << "================================================================\n";
                cout << "Session ended successfully. Goodbye, " << userName << "!\n";
                break;
            }
        }
        catch (const exception &error)
        {
            cout << "An unexpected error occurred: " << error.what() << endl;
            cout << "Please try again.\n";
        }

        if (menuChoice != 7)
        {
            cout << "\n--- Press Enter to return to main menu ---";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (menuChoice != 7);

    return 0;
}