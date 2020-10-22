class Simple {
	public double x;
	public String toString() {
		String s = "Oto ja: metoda toString() klasy Simple. Chce tylko powiedziec, ze x = " + x;
		return s;
	}
}

class Start {
	public static void main( String[] argv ) {
		Simple s = new Simple();
		s.x = 0.01;
		System.out.println( s );
	}
}
