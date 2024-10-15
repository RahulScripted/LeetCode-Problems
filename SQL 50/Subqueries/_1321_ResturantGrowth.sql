-- Table: Customer

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | customer_id   | int     |
-- | name          | varchar |
-- | visited_on    | date    |
-- | amount        | int     |
-- +---------------+---------+

-- 1.  In SQL,(customer_id, visited_on) is the primary key for this table.

-- 2.  This table contains data about customer transactions in a restaurant.

-- 3.  visited_on is the date on which the customer with ID (customer_id) has visited the restaurant.
-- amount is the total paid by a customer.
 

-- You are the restaurant owner and you want to analyze a possible expansion (there will be at least one customer every day). Compute the moving average of how much the customer paid in a seven days window (i.e., current day + 6 days before). average_amount should be rounded to two decimal places. Return the result table ordered by visited_on in ascending order.






SELECT DISTINCT visited_on,
        SUM(amount) OVER w AS amount,
        ROUND((SUM(amount) OVER w)/7, 2) AS average_amount
    FROM customer
    WINDOW w AS ( 
        ORDER BY visited_on
        RANGE BETWEEN interval 6 day PRECEDING AND current ROW
    )
Limit 6, 999;