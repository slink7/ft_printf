#include <stdio.h>

#include "libft/libft.h"

//cspdiuxX%

//-0.
//# +

/*BONUS A*/
//-//%-[0-9]*[cspdiuxX] ???
//0//%0[diuxX]
//.//\.(\*|[0-9]*)

/*BONUS B*/
//#//%#[xX]
// //% [di]
//+//%+[di]

#define PREFIX		0b00001
#define ZERO_PAD	0b00010
#define LEFT_ALIGN	0b00100
#define SPACE		0b01000
#define SIGNED		0b10000

typedef struct s_conv_spec {
	char	flags; //Handles [#0- +]
	int		field_width; //Handles minimum field width
	int		precision; //Handles max string len | min digits
	char	specifier; // conversion specifier
	int		length;
}	t_conv_spec;

int	flag_predicat(char c)
{
	const char	*flags = "#0- +";
	char		*out;

	out = ft_strchr(flags, c);
	if (out)
		return (out - flags + 1);
	return (0);
}

int	read_flags(t_conv_spec *out, char *str, int *k)
{
	int	temp;

	temp = flag_predicat(str[*k]);
	while (temp && ((*k)++))
	{
		out->flags |= 1 << temp;
		temp = flag_predicat(str[*k]);
	}
	return (1);
}

int	read_number(int	*out, char *str, int *k)
{
	int	offset;

	if (str[*k] == '*' && ((*k)++))
	{
		printf("READ FROM VAARG");
		return (1);
	}
	*out = 0;
	offset = str[*k] - '0';
	while (offset >= 0 && offset <= 9 && ((*k)++))
	{
		*out = *out * 10 + offset;
		offset = str[*k] - '0';
	}
	return (1);
}

int	read_conversion_specification(t_conv_spec *out, char *str)
{
	int		k;
	char	*temp;

	k = 0;
	if (str[k++] != '%')
		return (0);
	read_flags(out, str, &k);
	read_number(&out->field_width, str, &k);
	if (str[k] == '.' && k++)
		read_number(&out->precision, str, &k);
	temp = ft_strchr("cspdiuxX%", str[k++]);
	if (!temp)
		return (0);
	out->specifier = *temp;
	out->length = k;
	return (1);
}

int	main() {
	t_conv_spec	conv_spec = {0};

	int out = read_conversion_specification(&conv_spec, "%+#-+126.69s4654g4d6fg");
	printf("Success : %d\n", out);
	printf("Flags : %d\n", conv_spec.flags);
	printf("Field_width : %d\n", conv_spec.field_width);
	printf("Precision : %d\n", conv_spec.precision);
	printf("Specifier : %c\n", conv_spec.specifier);
	printf("Length : %d\n", conv_spec.length);

}