class Solution {
public:
int bestClosingTime(std::string customers) {

    int customers_missed = 0;
    int un_needed_hours = 0;
    int lowest_penalty = 0;
    int result = 0;

    for(int i = 0; i<customers.length(); i++){
        if(customers[i] == 'Y'){
            customers_missed++;
        }
    }

    lowest_penalty = customers_missed;

    for(int i = 0; i<customers.size(); i++){
        if(customers[i] == 'Y'){
            customers_missed--;
        }else{
            un_needed_hours++;
        }

        if(lowest_penalty > (customers_missed + un_needed_hours)) {
            result = i + 1;
            lowest_penalty = (customers_missed + un_needed_hours);
        }
    }

    return result;
}
};
