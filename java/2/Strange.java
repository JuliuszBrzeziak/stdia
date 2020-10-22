class Strange {
	public double x;
	public double y;
	private static double z;
	
	public static double getZ() {
	   return z;
	}
	
	public static void sumaXYdoZ( Strange dr ) {

		z = dr.x + dr.y;
	}
}

class Start {
	public static void main( String[] argv ) {
		Strange s = new Strange();
		s.x = 1.0;
		s.y = 2.0;
		System.out.println( "Przed wywolaniem sumaXYdoZ mamy Z = " + Strange.getZ() );
		s.sumaXYdoZ( s );
		System.out.println( "Po wywolaniu sumaXYdoZ mamy Z = " + Strange.getZ() );
	}
}
