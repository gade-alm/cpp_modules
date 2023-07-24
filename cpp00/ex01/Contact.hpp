#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;

	public:
		void		set_first(std::string	first);
		void		set_last(std::string	last);
		void		set_nick(std::string	nick);
		void		set_number(std::string	num);
		void		set_secret(std::string	darkest);
		std::string print_name(void);
		std::string	print_last(void);
		std::string	print_nick(void);
		std::string	print_number(void);
		std::string	print_secret(void);
		int			get_info(int num);
};

#endif
