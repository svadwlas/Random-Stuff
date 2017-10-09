import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * Created by S.Vadwlas
 */
public class ReflectionSpeedTester {



    public  static final  int COUNTER = 1000000000;
    public static long CNT = 0;


    private static class TestClass {

        public void testClassMethod(String st1, String st2, String st3){

            CNT++;


        }




    }


    public static void main(String[] args)  throws NoSuchMethodException{

        TestClass tcl = new TestClass();
        Method tm = tcl.getClass().getMethod("testClassMethod", String.class, String.class, String.class );

        String st1 = "FirstString";
        String st2 = "SecondString";
        String st3 = "ThirdString";


        methodUsingReflection(tcl, tm, st1, st2, st3, COUNTER/10 );
        methodUsingStatic(tcl, st1, st2, st3, COUNTER/10);



        long reflectionTime = System.nanoTime();
        methodUsingReflection(tcl, tm, st1, st2, st3, COUNTER);
        reflectionTime = System.nanoTime()-reflectionTime;


        long regularTime = System.nanoTime();

        methodUsingStatic(tcl, st1, st2, st3, COUNTER);
        regularTime = System.nanoTime() - regularTime;


        System.out.println(reflectionTime);
        System.out.println(regularTime);


        //Get it in seconds

        System.out.println(reflectionTime/1000000000);
        System.out.println(regularTime/1000000000);
        System.out.println((double)reflectionTime/(double) regularTime);

        // Decrease in speed for using reflection (In terms of time percent)


        System.out.println("Decrease in speed " + (((double)reflectionTime/(double)regularTime)-1)*100);

    }


    private static void methodUsingStatic (TestClass tcl, String st1, String st2, String st3, int counter ){


        for (int i =0; i < counter; i++){


            tcl.testClassMethod(st1, st2, st3);
        }




    }


    private static void methodUsingReflection(TestClass tcl, Method tm, String st1, String st2, String st3, int counter){

        for (int i =0; i <counter; i++){
            try{

                tm.invoke(tcl, st1, st2, st3);

            }


            catch (IllegalArgumentException e){

            }
            catch (IllegalAccessException e){

            }
            catch (InvocationTargetException e){

            }


        }



    }











}
