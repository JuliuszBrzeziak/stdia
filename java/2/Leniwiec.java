class Simple {
	public double x;
}

class Leniwiec {
	static void testerek( Simple s ) {
		if ( (  s!= null ) && ( s.x > 0.0 ) ) {
			System.out.println( "1. Dostarczono do mnie referencje do obiektu klasy Simple, ktory zawiera x > 0.0");
		} else { 
			System.out.println( "1. Nie wiem co dostarczono - ale mi sie to wcale nie podoba !!! " );
		}
		if ( (  s!= null ) & ( s.x > 0.0 ) ) {
			System.out.println( "2. Dostarczono do mnie referencje do obiektu klasy Simple, ktory zawiera x > 0.0");
		} else { 
			System.out.println( "2. Nie wiem co dostarczono - ale mi sie to wcale nie podoba !!!" );
		}
		
	}

	public static void main( String[] argv ) {
		Simple si = new Simple();
		si.x = 1.0;
		System.out.println( "Zaraz wywolam testerek( si ) - patrz uwaznie co sie bedzie dzialo" );
		testerek( si );
		System.out.println( "Zaraz wywolam testerek( null ) - patrz uwaznie co sie bedzie dzialo" );
		testerek( null );
	}
}
