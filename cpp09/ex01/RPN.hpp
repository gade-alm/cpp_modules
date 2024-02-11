#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <cstring>

void	checkValues( char *dataEntry );
void	calcValue( char* valueEntry );
int		resultOperation( std::stack<int> &values, char operand );

#endif