#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <unistd.h>
//using namespace for sfml and std
using namespace sf;
using namespace std;

//function prototypes for display and name_score
void display(int x[][8],int y[][8],int col[][8],int row[][8],int kind[][8]);
void name_score(RenderWindow &app, string &name, int &level, int &score, int &moves,int &count);
//main function
int main()
{
        //declaring arrays for data storage
        int x[8][8];
        int y[8][8];
        int col[8][8];
        int row[8][8];
        int kind[8][8];
        //calling display function
        display(x,y,col,row,kind);

    return 0;
}
//definition for function draw_lines
void draw_lines(RenderWindow &app)
{
        //declaring line as a Reactangle Shape
        RectangleShape line;
        //setting line position with x and y values
        line.setPosition(450,50);
        //setting line color
        line.setFillColor(Color::Blue);
        //setting line size
        line.setSize(Vector2f(240,3));
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,60);
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,70);
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,80);
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,90);
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,100);
        //drawing line
        app.draw(line);
        //setting line position with x and y values
        line.setPosition(450,110);
        //drawing line
        app.draw(line);
}

//Definition for function kind_count
void kind_count(int kind[][8],int &s1,int &s2,int &s3,int &s4,int &s5,int &s6,int &s7,int &i,int &j)
{
                //comparing and counting each kind
                if(kind[i][j]==0)
                        s1++;
                if(kind[i][j]==1)
                        s2++;
                if(kind[i][j]==2)
                        s3++;
                if(kind[i][j]==3)
                        s4++;
                if(kind[i][j]==4)
                        s5++;
                if(kind[i][j]==5)
                        s6++;
                if(kind[i][j]==6)
                        s7++;
}
//definition of function score_update_4
void score_update_4(int kind[][8],int &score, int &i, int &j)
{
        //comparing and increasing score according to each kind
        if(kind[i][j]==0)
                score+=10*4;
        else if(kind[i][j]==1)
                score+=25*4;
        else if(kind[i][j]==2)
                score+=35*4;
        else if(kind[i][j]==3)
                score+=20*4;
        else if(kind[i][j]==4)
                score+=5*4;
        else if(kind[i][j]==5)
                score+=30*4;
        else if(kind[i][j]==6)
                score+=15*4;
}

//definition of function score_update_3
void score_update_3(int kind[][8],int &score, int &i, int &j)
{
        //comparing and increasing score according to each kind
        if(kind[i][j]==0)
                score+=10*3;
        else if(kind[i][j]==1)
                score+=25*3;
        else if(kind[i][j]==2)
                score+=35*3;
        else if(kind[i][j]==3)
                score+=20*3;
        else if(kind[i][j]==4)
                score+=5*3;
        else if(kind[i][j]==5)
                score+=30*3;
        else if(kind[i][j]==6)
                score+=15*3;
}

//definition of function data_entry
void data_entry(int kind[][8],int col[][8], int row[][8], int x[][8], int y[][8],int &s1,int &s2,int &s3,int &s4,int &s5,int &s6,int &s7)
{
        //specifying tile size
        int ts=54;
        //seeding for random function
        srand(time(0));
        //8x8 loop to store kind,column,row and x-y coordinate data in arrays
        for(int i=1;i<=8;i++)
        {
                for(int j=1;j<=8;j++)
                {
                        kind[i][j]=rand()%7;
                        col[i][j]=j;
                        row[i][j]=i;
                        x[i][j]=j*ts;
                        y[i][j]=i*ts;
                        //calling kind_count function
                        kind_count(kind,s1,s2,s3,s4,s5,s6,s7,i,j);
                }
        }
}
//definition of function user_input
void user_input(string &name, int &level)
{
        //taking user name input
        cout<<"\t\tUser name"<<endl;
        cout<<"\t\t---------"<<endl;
        cout<<"\nEnter user name: ";
        getline(cin,name);
        //taking level input until correct value is entered
        while(1)
        {
                cout<<"\nEnter level (level1=Normal Gameplay || level2=Time Constraint): ";
                cin>>level;
                if(level==1 || level==2)
                        break;
                else
                        cout<<"Invalid level!"<<endl;
        }
}
//definition of function result_display
void result_display(int &level, int &moves, string &name, int &score,int &timer, int &count, int &s1,int &s2,int &s3,int &s4,int &s5,int &s6,int &s7,RenderWindow &app,int x[][8], int y[][8], int col[][8], int row[][8], int kind[][8])
{
        //declaring static variable to run some code only once
        static int flag=0;
        //if moves<=0 lose screen is displayed and game ends
                if(moves<=0)
                {
                        //clearing rendered window
                        app.clear();
                        //declaring Texture type variable
                        Texture t5;
                        //loading lose screen image from jpeg file
                        t5.loadFromFile("lose.jpeg");
                        //drawing background
                        Sprite background5(t5);
                        app.draw(background5);
                        //displaying rendered window
                        app.display();
                        //delay for 3 seconds
                        sleep(3);
                        //prompting game over if moves<=0
                        cout<<"\nGame Over!"<<endl;
                        cout<<"Moves ended."<<endl;
                        cout<<"\n"<<name<<" your score is: "<<score<<endl;
                        exit(1);
                }
                //if animal inventory reaches its limit then start level 2
                if(s1>=24 && s2>=24 && s3>=24 && s4>=24 && s5>=24 && s6>=24 && s7>=24)
                {
                        //static variable used
                        flag++;
                        if(flag==1)
                        {
                                cout<<"-------------------------"<<endl;
                                cout<<"Level 2 Started!"<<endl;
                                cout<<"-------------------------"<<endl;
                                //delay for 1second
                                sleep(1);
                                //calling draw_lines function to set progress bar empty again for level 2
                                draw_lines(app);
                                //setting animal count to 0 for level 2
                                s1=s2=s3=s4=s5=s6=s7=0;
                                //setting moves to 60 again for level 2
                                moves=60;

                        }
                        //changing level if animal inventory is fulled
                        level=2;
                }

                if(level==2)
                {
                        //if animal inventory is full for level2 then display win screen
                        if(s1>=24 && s2>=24 && s3>=24 && s4>=24 && s5>=24 && s6>=24 && s7>=24)
                        {
                                //clearing rendered window
                                app.clear();
                                //declaring texture type variable
                                Texture t4;
                                //loading win window image from a file
                                t4.loadFromFile("win.jpeg");
                                //drawing background
                                Sprite background3(t4);
                                app.draw(background3);
                                //displaying rendered window
                                app.display();
                                //prompting win message
                                cout<<"\nYou win!"<<endl;
                                cout<<"\nLevel 1 and 2 completed successfully!"<<endl;
                        }
                        //increasing timer variable to calculate time
                        timer++;
                        //calculating time in seconds
                        if(timer%50==0)
                        {
                                //displaying name and score on rendered window in Graphics
                                name_score(app, name, level, score, moves,count);
                                cout<<"Remaining seconds: "<<(count--)<<" Score="<<score<<" Moves left: "<<moves<<endl;
                        }
                        //if time is 0 then end the game
                        if(level==2 && timer==6000)   //6000
                        {
                                //clearing rendered window
                                app.clear();
                                //declaring texture variable
                                Texture t3;
                                //Loading lose windows image from a file
                                t3.loadFromFile("lose.jpeg");
                                //drawing background
                                Sprite background2(t3);
                                app.draw(background2);
                                //displaying rendered window
                                app.display();
                                //prompting game over message
                                cout<<"Game Over!"<<endl;
                                cout<<"Time ended!"<<endl;
                                //delay for 3 seconds
                                sleep(3);
                                cout<<"\n"<<name<<" your score is: "<<score<<endl;
                                //exit rendered window
                                exit(1);
                        }
                }
                else
                        cout<<"Score="<<score<<" Moves left: "<<moves<<endl;
}
//definition for function click1
void click1(int &click, Vector2i &pos, int &x0, int &y0)
{
        //specifying tiles size
        int ts=54;
        //for 1st click storing cursor position in x-y coordinates
        if(click==1)
        {
              x0=pos.x/ts;
              y0=pos.y/ts;
        }
}
//definition for function click2
void click2(int &click, Vector2i &pos,int &moves,int &x0, int &x1, int &y0, int &y1, int kind[][8],int x[][8],int y[][8])
{
        //specifying tile size
        int ts=54;
        //for click2 storing cursor position in x-y coordinates
        if(click==2)
        {
                x1=pos.x/ts;
                y1=pos.y/ts;
                //calculating if both boxes are adjecent in x-axis then swap them
                if((x0-x1)==1 && y0==y1)
                {
                                //pixel to pixel animation for box swap
                                //if boxes are swap then swap their corresponding kind values
                                if(x[y0][x0]==x1*ts)
                                {
                                        //after each swap decreasing moves by 1
                                        moves-=1;
                                        //setting coordinates values back to original
                                        x[y0][x0]=x0*ts;
                                        x[y1][x1]=x1*ts;
                                        //swaping kinds
                                        int temp=kind[y0][x0];
                                        kind[y0][x0]=kind[y1][x1];
                                        kind[y1][x1]=temp;
                                        //setting click count back to 0
                                        click=0;
                                }
                                else
                                {
                                        //increasing and decreasing boxes screen value by 1 pixel until they swap
                                        x[y0][x0]-=3;
                                        x[y1][x1]+=3;
                                }
                }
                //calculating if both boxes are adjecent in x-axis then swap them
                else if((x1-x0)==1 && y0==y1)
                {
                                //pixel to pixel animation for box swap
                                //if boxes are swap then swap their corresponding kind values
                                if(x[y1][x1]==x0*ts)
                                {
                                        //after each swap decreasing moves by 1
                                        moves-=1;
                                        //setting coordinates values back to original
                                        x[y0][x0]=x0*ts;
                                        x[y1][x1]=x1*ts;
                                        //swaping kinds
                                        int temp=kind[y0][x0];
                                        kind[y0][x0]=kind[y1][x1];
                                        kind[y1][x1]=temp;
                                        //setting click count back to 0
                                        click=0;
                                }
                                else
                                {
                                        //increasing and decreasing boxes screen value by 1 pixel until they swap
                                        x[y1][x1]-=3;
                                        x[y0][x0]+=3;
                                }

                }
                //calculating if both boxes are adjecent in y-axis then swap them
                if((y1-y0)==1 && x0==x1)
                {
                        //pixel to pixel animation for box swap
                        //if boxes are swap then swap their corresponding kind values
                        if(y[y1][x1]==y0*ts)
                        {
                                //after each swap decreasing value of moves by 1
                                moves-=1;
                                //setting coordinates values back to original
                                y[y0][x0]=y0*ts;
                                y[y1][x1]=y1*ts;
                                //swaping kinds
                                int temp=kind[y0][x0];
                                kind[y0][x0]=kind[y1][x1];
                                kind[y1][x1]=temp;
                                //setting click count back to 0
                                click=0;
                        }
                        else
                        {
                                //increasing and decreasing boxes screen value by 1 pixel until they swap
                                y[y1][x1]-=3;
                                y[y0][x0]+=3;
                        }
                }
                //calculating if both boxes are adjecent in y-axis then swap them
                else if((y0-y1)==1 && x0==x1)
                {
                        //pixel to pixel animation for box swap
                        //if boxes are swap then swap their corresponding kind values
                        if(y[y0][x0]==y1*ts)
                        {
                                //after each swap decreasing moves by 1
                                moves-=1;
                                //setting coordinates values back to original
                                y[y0][x0]=y0*ts;
                                y[y1][x1]=y1*ts;
                                //swaping kinds
                                int temp=kind[y0][x0];
                                kind[y0][x0]=kind[y1][x1];
                                kind[y1][x1]=temp;
                                //setting click count back to 0
                                click=0;
                        }
                        else
                        {
                                //increasing and decreasing boxes screen value by 1 pixel until they swap
                                y[y0][x0]-=3;
                                y[y1][x1]+=3;
                        }
                }

        }
}
//definition for function match
void match(int &i, int &j,int kind[][8], int &score)
{
        //Constraints for 1st and last rows and columns
        //Constraint for 1st column
        if(j==1 || j-4<1)
        {
                //matching any 4 kinds in x-axis adjecently
               if(kind[i][j+3]==kind[i][j] && kind[i][j+1]==kind[i][j] && kind[i][j+2]==kind[i][j])
                {
                        //if matched updating score
                        score_update_4(kind,score,i,j);
                        //making matched boxes invisible
                        kind[i][j+3]=7;
                        kind[i][j]=7;
                        kind[i][j+1]=7;
                        kind[i][j+2]=7;
                }
        }
        //Constraint for last column
        else if(j==8 || j+4>8)
        {
                //matching any 4 kinds in x-axis adjecently backwards
                if(kind[i][j-1]==kind[i][j] && kind[i][j-2]==kind[i][j] && kind[i][j-3]==kind[i][j])
                {
                        //if matched updating Score
                        score_update_4(kind,score,i,j);
                        //turning matched boxes invisible
                        kind[i][j-1]=7;
                        kind[i][j]=7;
                        kind[i][j-2]=7;
                        kind[i][j-3]=7;
                }
        }
        else
        {
                //matching any 4 kinds in x-axis adjecently
                if(kind[i][j-1]==kind[i][j] && kind[i][j+1]==kind[i][j] && kind[i][j+2]==kind[i][j])
                {
                        //if matched updating score
                        score_update_4(kind,score,i,j);
                        //turning matched values invisible
                        kind[i][j-1]=7;
                        kind[i][j]=7;
                        kind[i][j+1]=7;
                        kind[i][j+2]=7;
                }
        }
        //Constraint for 1 column
        if(j==1 || j-3<1)
        {
                //matching any 3 kinds in x-axis adjecently
                if(kind[i][j+2]==kind[i][j] && kind[i][j+1]==kind[i][j])
                {
                        //if match found updating score
                        score_update_3(kind,score,i,j);
                        //turning matched boxes invisible
                        kind[i][j+2]=7;
                        kind[i][j]=7;
                        kind[i][j+1]=7;
                }
        }
        //Constraint for last column
        else if(j==8 || j+3>8)
        {
                //matching any 3 kinds in x-axis adjecently
                if(kind[i][j-2]==kind[i][j] && kind[i][j-1]==kind[i][j])
                {
                        //updating score if matched
                        score_update_3(kind,score,i,j);
                        //turning matched boxes invisible
                        kind[i][j-2]=7;
                        kind[i][j]=7;
                        kind[i][j-1]=7;
                }
        }
        else
        {
                //matching any 3 kinds in x-axis adjecently
                if(kind[i][j-1]==kind[i][j] && kind[i][j+1]==kind[i][j])
                {
                        //updating score if matched
                        score_update_3(kind,score,i,j);
                        //turning matched boxes invisible
                        kind[i][j-1]=7;
                        kind[i][j]=7;
                        kind[i][j+1]=7;
                }
        }
        //checking match in y-axis(verticaly)
        if(kind[i-1][j]==kind[i][j] && kind[i+1][j]==kind[i][j] && kind[i+2][j]==kind[i][j])
        {
                //updating score if any matched
                score_update_4(kind,score,i,j);
                //turning matched boxes invisible
                kind[i-1][j]=7;
                kind[i][j]=7;
                kind[i+1][j]=7;
                kind[i+2][j]=7;
        }
        if(kind[i-1][j]==kind[i][j] && kind[i+1][j]==kind[i][j])
        {
                //updating score
                score_update_3(kind,score,i,j);
                //turning boxes invisible if matched
                kind[i-1][j]=7;
                kind[i][j]=7;
                kind[i+1][j]=7;
                }
}
//definition of function kind_names
void kind_names(RenderWindow &app)
{
        //creating font type variable
        Font myfont;
        //error handling if font file is unable to load
        if (!myfont.loadFromFile("arial.ttf"))
        {
                cout<<"Error Loading fonts!"<<endl;
        }
        //setting text for fonts with size
        sf::Text text("Camel",myfont,10);
        //setting position for text
        text.setPosition(450,50);
        //drawing text on rendered window
        app.draw(text);
        //setting text
        text.setString("Elephant");
        //setting position
        text.setPosition(450,60);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Tiger");
        //setting position
        text.setPosition(450,70);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Sheep");
        //setting position
        text.setPosition(450,80);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Giraffe");
        //setting position
        text.setPosition(450,90);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Deer");
        //setting position
        text.setPosition(450,100);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Goat");
        //setting position
        text.setPosition(450,110);
        //drawing text
        app.draw(text);
}
//definition for function name_score
void name_score(RenderWindow &app, string &name, int &level, int &score,int &moves,int &count)
{
        //setting font type variable
        Font myfont;
        //Loading fonts from ttf type file
        if (!myfont.loadFromFile("arial.ttf"))
        {
                cout<<"Error Loading fonts!"<<endl;
        }
        //setting text
        sf::Text text("Name",myfont,15);
        //setting color for text
        text.setFillColor(Color::Yellow);
        //setting position for text
        text.setPosition(450,130);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Level");
        //setting position for text
        text.setPosition(530,130);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Score");
        //setting position for text
        text.setPosition(610,130);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("Moves");
        //setting position for text
        text.setPosition(690,130);
        //drawing text
        app.draw(text);

        //setting color for text
        text.setFillColor(Color::White);
        //setting text
        text.setString(name);
        //setting position for text
        text.setPosition(450,150);
        //drawing text
        app.draw(text);
        //setting text
        text.setString(to_string(level));
        //setting position for text
        text.setPosition(530,150);
        //drawing text
        app.draw(text);
        //setting text
        text.setString(to_string(score));
        //setting position for text
        text.setPosition(610,150);
        //drawing text
        app.draw(text);
        //setting text
        text.setString("    ");
        //setting position for text
        text.setPosition(690,150);
        //drawing text
        app.draw(text);
        //setting text
        text.setString(to_string(moves));
        //setting position for text
        text.setPosition(690,150);
        //drawing text
        app.draw(text);

        text.setCharacterSize(50);
        text.setFillColor(Color::Yellow);
        text.setString("Timer");
        text.setPosition(530,200);
        app.draw(text);

        text.setCharacterSize(50);
        //setting color for text
        text.setFillColor(Color::Blue);
        //setting text
        text.setString("    ");
        //setting position for text
        text.setPosition(550,270);
        app.draw(text);
        //setting text
        text.setString(to_string(count));
        //setting position for text
        text.setPosition(550,270);
        //drawing text
        app.draw(text);

}
//Definition for function display
void display(int x[][8],int y[][8],int col[][8],int row[][8],int kind[][8])
{
        //specifying tile size
        int ts = 54;
        //specifying offset Vector
        Vector2i offset(-48,-30);
        //setting position Vector
        Vector2i pos;
        string name;
        //declaring variables
        int level,timer=0,count=119,moves=60;
        int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0;
        int score=0;
        //calling user_input function
        user_input(name,level);
        //seeding for random number
    srand(time(0));
    //creating render window of 740x480 with title Menagerie
    RenderWindow app(VideoMode(740,480), "Menagerie");
    //setting framerate
    app.setFramerateLimit(60);
    //declaring texture variable
    Texture t1,t2;
    //loading background image and gems from file
    t1.loadFromFile("background.png");
    t2.loadFromFile("gems.png");
    Sprite background(t1), gems(t2);
    int click=0,x0,y0,x1,y1;
    //calling data_entry function
    data_entry(kind,col,row,x,y,s1,s2,s3,s4,s5,s6,s7);
    if(level==1)
        {
                cout<<"Playing in Normal Mode."<<endl;
        }
        //performing actions while app windows is open
        while(app.isOpen())
        {
                //calling result_display function to display result
                result_display(level,moves,name,score,timer,count,s1,s2,s3,s4,s5,s6,s7,app,x,y,col,row,kind);
                //creating Event type variable to handle mouse events
                Event e;
                while(app.pollEvent(e))
                {
                        //closing rendered window if close button is pressed
                        if(e.type == Event::Closed)
                                app.close();
                        //if any mouse button is pressed
                        if(e.type == sf::Event::MouseButtonPressed)
                        {
                                //check if pressed button is Left-click
                                if(e.mouseButton.button == sf::Mouse::Left)
                                {
                                        //incrementing click variable
                                        click++;
                                        //storing mouse position is Vector variable
                                        pos=Mouse::getPosition(app)-offset;
                                }
                        }
                }
        //calling click1 and click2 functions
        click1(click,pos,x0,y0);
        click2(click,pos,moves,x0,x1,y0,y1,kind,x,y);
        //if click>=3 click is back to 0
        if(click>3)
                click=0;
        //matching animals by calling match function for each kind in array
        for(int i=1;i<=8;i++)
        {
                for(int j=1;j<=8;j++)
                {
                        match(i,j,kind,score);
                }
        }
        //draw background
        app.draw(background);
        //calling functions to draw progress bars and display kind names on RenderWindow
        draw_lines(app);
        kind_names(app);
        name_score(app, name, level, score, moves,count);
        RectangleShape line;
        //for animal1
        if(s1)
        {
                //setting color for line(progress bar)
                line.setFillColor(Color::Red);
                //setting position for line
                line.setPosition(450,50);
                if(s1>=24)
                        line.setSize(Vector2f(240,3));//size for line
                else
                        line.setSize(Vector2f(s1*10,3));
                //drawing line
                app.draw(line);
        }
        //for animal2
        if(s2)
        {
                //drawind progress bar
                line.setFillColor(Color::Red);
                line.setPosition(450,60);
                if(s2>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s2*10,3));
                app.draw(line);
        }
        //for animal3
        if(s3)
        {
                //drawind progress bar
                line.setFillColor(Color::Red);
                line.setPosition(450,70);
                if(s3>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s3*10,3));
                app.draw(line);
        }
        //for animal4
        if(s4)
        {
                //drawind progress bar
                line.setFillColor(Color::Red);
                line.setPosition(450,80);
                if(s4>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s4*10,3));
                app.draw(line);
        }
        //for animal5
        if(s5)
        {
                //drawind progress bar
                line.setFillColor(Color::Red);
                line.setPosition(450,90);
                if(s5>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s5*10,3));
                app.draw(line);
        }
        //for animal6
        if(s6)
        {
                line.setFillColor(Color::Red);
                line.setPosition(450,100);
                if(s6>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s6*10,3));
                app.draw(line);
        }
        //for animal7
        if(s7)
        {
                //drawind progress bar
                line.setFillColor(Color::Red);
                line.setPosition(450,110);
                if(s7>=24)
                        line.setSize(Vector2f(240,3));
                else
                        line.setSize(Vector2f(s7*10,3));
                app.draw(line);
        }
        srand(time(0));
        //loop for 8x8 grid
        for(int i=1;i<=8;i++)
        {
                for(int j=1;j<=8;j++)
                {
                        //if any invisible tile found then drop all tiles above it
                        if(kind[i][j]==7)
                        {
                                //for 1st tile generate random no
                                if(i==1)
                                {
                                        kind[i][j]=rand()%7;
                                        kind_count(kind,s1,s2,s3,s4,s5,s6,s7,i,j);
                                }
                                else if(y[i-1][j]==i*ts)//animate tile for down falling
                                {
                                        y[i-1][j]=(i-1)*ts;
                                        kind[i][j]=kind[i-1][j];
                                        kind[i-1][j]=7;
                                }
                                else
                                {
                                        y[i-1][j]+=3;
                                }
                        }
                        //cutting gems image to required kind
                        gems.setTextureRect(IntRect(kind[i][j]*49,0,49,49));
                        //setting position
                        gems.setPosition(x[i][j]-45,y[i][j]-28);
                        //drawing gems(animals)
                        app.draw(gems);
                }
        }
        //displaying main rendered window
        app.display();

        }
}



