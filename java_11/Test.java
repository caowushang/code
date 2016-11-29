import java.awt.*;
import java.awt.event.*;
class Calculated extends Frame implements ActionListener{

	TextField text1,text2,text3;
	Button buttonH,buttonC,buttonJ,buttonS;
	Calculated(String s){

		super(s);
		setLayout(new FlowLayout());
		text1=new TextField(10);
		text2=new TextField(10);
		text3=new TextField(17);
		buttonH=new Button("加");
		buttonC=new Button("差");
		buttonJ=new Button("积");
		buttonS=new Button("除");
		add(text1);
		add(text2);
		add(text3);
		text3.setEditable(false);
		add(buttonH);
		add(buttonC);
		add(buttonJ);
		add(buttonS);
		buttonH.addActionListener(this);
		buttonC.addActionListener(this);
		buttonJ.addActionListener(this);
		buttonS.addActionListener(this);
		addWindowListener(new WindowAdapter(){

			public void windowClosing(WindowEvent e){

				System.exit(0);
			}
		}
		);
		setBounds(100,100,160,180);
		setVisible(true);
		validate();
	}
	public void actionPerformed(ActionEvent e){

		double num1=0,num2=0,totle=0;
		try{

			num1=Double.parseDouble(text1.getText());
			num2=Double.parseDouble(text2.getText());
			if(e.getSource()==buttonH){

				totle=num1+num2;
				text3.setText("和"+totle);
			}
			else if(e.getSource()==buttonC) {

				totle=num1-num2;
				text3.setText("差"+totle);
			}
			else if(e.getSource()==buttonJ) {

				totle=num1*num2;
				text3.setText("积"+totle);
			}
			else if(e.getSource()==buttonS){

				totle=num1/num2;
				text3.setText("商"+totle);
			}
		}
		catch(NumberFormatException event){

			text3.setText("请输入数字字符!");
		}}}
public class Test{

	public static void main(String args[]) {

		Calculated calc=new Calculated("计算");
	}}
