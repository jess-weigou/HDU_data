package 异常处理;

class TestExceptions {
    public static void main(String[] arg) {
        int []args = new int[3];
            try {
                for ( int i = 0; true; i++ ) {
                    args[i] = i;
                    System.out.println("args[" + i + "] is '" + args[i] + "'");
                }
            }catch (ArrayIndexOutOfBoundsException e){
                System.out.println(e.toString());
                System.out.println("Quit");
            }
    }
}

