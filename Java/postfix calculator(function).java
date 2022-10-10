
public class ASS5function {
    public static String Transform(String str) {
		str = str.replace("+"," + ");
		str = str.replace("-"," - ");
		str = str.replace("*"," * ");
		str = str.replace("/"," / ");
		str = str.replace("^"," ^ ");
		str = str.replace("("," ( ");
		str = str.replace(")"," ) ");
		return str;
	}
	
	public static boolean isNumber(String str) {
		boolean check = true;
		try {
			Double.parseDouble(str);
		}catch (Exception e) {
			check = false;
		}
		return check;
	}
	
	public static int checkfunction(String str) {
		String [] func = {"sin","cos","tan","asin","acos","atan","sqrt","log","exp","abs"};
		int ans = -1;
		for(int i=0;i<func.length;i++)
			if(str.equalsIgnoreCase(func[i]))
				ans = i;
		return ans;
	}
	
	public static boolean isConstant(String str) {
		String [] cons = {"pi","ans"};
		boolean ans = false;
		for(int i=0;i<cons.length;i++)
			if(str.equalsIgnoreCase(cons[i]))
				ans = true;
		return ans;
	}
	
	public static void changesignoperator(String token[]) {
		if(token[0].equals("-"))
			token[0] = "!";
		for(int i=0;i<token.length-1;i++)
			if(token[i+1].equals("-") && (token[i].matches("[-+/(*\\^]")))
				token[i+1] = "!";
	}
	
	public static int checkgroup(String str) {
		if(isNumber(str))
			return 1;
		else if(isConstant(str))
			return 1;
		else if(str.matches("[-+]"))
			return 2;
		else if(str.matches("[*/]"))
			return 3;
		else if(str.equals("^"))
			return 4;
		else if(str.equals("!"))
			return 5;
		else if(str.equals("("))
			return 7;
		else if(str.equals(")"))
			return 8;
		else if(checkfunction(str)>-1)
			return 6;
		else 
			return 0;
	}
	
	public static int checkstate(String [] token) {
		int state = 0,next = 0,b = 0;
		for(int i=0;i<token.length && state>=0;i++) {
			state = next;
			next = checkgroup(token[i]);
			if(next >= 2 && next <= 4) next = 2;
			if(next == 0)
				state = -1;
			if(next == 7) 
				b++;
			else if(next == 8)
				b--;
			if(b < 0)
				state = -1; 
			else if(state == 0 && (next == 8 || next == 2))
				state = -1; 
			else if(state == 1 && (next == 1 || next == 6 || next == 7))
				state = -1; 
			else if(state == 2 && (next == 2 || next == 8))
				state = -1; 
			else if(state == 5 && (next == 2 || next == 8))
				state = -1; 
			else if(state == 6 && (next != 7))
				state = -1; 
			else if(state == 7 && (next == 8 || next == 2))
				state = -1; 
		}
		if(b != 0 || state == -1)
			return -1;
		else
			return next;
	}
}
