export module airline_ticket;

import <string>;

export class AirlineTicket
{
public:
	double calculatePriceInDollars() const;          //// const method
	
	const std::string& getPassengerName() const;     //// const method + return a const reference
	void setPassengerName(const std::string& name);  //// Accept a const reference

	int getNumberOfMiles() const;                    //// const method
	void setNumberOfMiles(int miles);
	
	bool getHasEliteSuperRewardsStatus() const;      //// const method
	void setHasEliteSuperRewardsStatus(bool status);

private:
	std::string m_passengerName{ "Unknown Passenger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
};
