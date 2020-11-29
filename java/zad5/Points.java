import javax.swing.*;
import java.awt.*;

class MyJPanel extends JPanel {
   public void paintComponent( Graphics g ) {
      g.setColor( Color.orange );
      g.fillRect( 1,1,getWidth() / 2, getHeight() / 2 );
      g.setColor( Color.red );
      g.drawLine( 0,0, 100, 100 );
      g.setColor( Color.blue );
      g.fillOval( 200,200, 150, 100 );
   }
}

class Points {
   public static void main( String[] argv ) {
    JFrame ramka = new JFrame( "Moje okienko do " );
    ramka.getContentPane().add( new MyJPanel() );
    ramka.setSize( 400, 400 );
    ramka.setVisible( true );
    ramka.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
   }
}
