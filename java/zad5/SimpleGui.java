import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class SimpleGUI {
	JButton przycisk1;
	JButton przycisk2;
	JLabel etykietka;
	JFrame ramka;

	public static void main( String[] argv ) {
		SimpleGUI g = new SimpleGUI();
		g.work();
	}
	
	class KlasaWewnetrzna implements ActionListener {
		public void actionPerformed( ActionEvent e ) {
	            etykietka.setText( "Kliknieto przycisk 1" );			
		}
	}
	
	private void work() {
		ramka = new JFrame( "Moja ramka do zabawy z GUI" );
		ramka.setSize( 500, 100 );
		
		przycisk1 = new JButton( "Przycisk 1" );
		przycisk1.addActionListener( new KlasaWewnetrzna() );
		
		przycisk2 = new JButton( "Przycisk 2" );
		przycisk2.addActionListener( new ActionListener() {
		        public void actionPerformed(ActionEvent e) {  
	         	        etykietka.setText( "Kliknieto przycisk 2" );
         	        }
		} );

		etykietka = new JLabel( "Tutaj etykietka" );

        ramka.setLayout(new FlowLayout());

        ramka.getContentPane().add(przycisk1);
        ramka.getContentPane().add(przycisk2);

		// ramka.getContentPane().add( BorderLayout.EAST, przycisk1 );
		// ramka.getContentPane().add( BorderLayout.EAST, przycisk2 );
		ramka.getContentPane().add( BorderLayout.CENTER, etykietka );

		ramka.setVisible( true );
		ramka.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
	}
}
