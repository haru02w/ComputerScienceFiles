package sla;

import java.awt.GridLayout;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;

/**
 * Hello world!
 *
 */
public class App {
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame();
        frame.setLayout(new GridLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Add the ubiquitous "Hello World" label.
        JLabel label = new JLabel("Qual vc prefere?");
        frame.add(label);

        ButtonGroup radio = new ButtonGroup();
        JRadioButton btn1 = new JRadioButton("Arroz");
        JRadioButton btn2 = new JRadioButton("Feijão");
        radio.add(btn1);
        radio.add(btn2);
        frame.add(btn1);
        frame.add(btn2);


        //Display the window.
        frame.pack();
        frame.setSize(800,640);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}
