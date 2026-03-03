#include "ShrubberyCreationForm.hpp"

// CANONICAL FUNCTIONS
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",145,137), target(default){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm",145,137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (&other != this)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
	return *this;
}

// METHODS
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade > gradeToExecute)
        throw AForm::GradeTooLowException();
    std::ofstream = outfile((target + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("File open failed");
    outfile << R"(
                        &&          &%  &%#
                        &|         %@%&@&@
                    @&## &@&:        #&%%;&#%&@&@
                && @#%\@#@@%@% \___; |%%&#%@%##@%@
                % @ %#%@\&@#&@ &#   \&  @|%#&%@%  @
            &&&&##%#@#=  @ @&%#%     \ /### &&#%@#
            &    %&&&%@ \|%#&=@#@%#   :_:%@&#@%#&&@%
        %     %@%& @  &%   #&%&    ~    #@@#%&%&#@&
        %%#%&&  #@/_&_;_\~     @  #   =|  % @%##%##@ &
       # &:&%%@@~        |\           |_:;|&\&  @@&@#&@
    #@   &%%%@@      ://_;~\_____    ///   &#@#&#&%#@
   &@#@   #@@%_&@__/ /           \  ;    @#@&&@&&@##%#@
   &%   %@=//;_ : /               =|      %& @@@@&&&  @
          @                         ~    &  @   %  %
                                     \
                                     =|\
                                     ||      _~___;
                                     ||  __~_      _~__\
                                     ____               \
                                    ~|                    \
                                    ||               %&    | 
                                    ||            @%#_&    /    %
                       \_______.-./||\.__________/   @~&~~~   @##@&%
                        \   ~                 . /   @@@@/#&%|@&#@%#
                         \_____________________/   &&&%@%###~%&/&&
                            -               -        @#&&&@@@&##%@%
                                                      %&  %&@&%&#%#@
)";
}
