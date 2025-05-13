import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class part1 {
    public static void perform() {
        ArrayList<Integer> tracks = new ArrayList<>();

        try {
            // Split file into respective parts
            String file_contents = Files.readString(Path.of("input.txt"));
            String[] file_parts = file_contents.split("\n\n");

            // Create list of track values
            String[] track_freqs = file_parts[0].split("\n");
            for (String track_freq : track_freqs) {
                tracks.add(Integer.parseInt(track_freq));
            }

            // Swap track values
            String[] swaps = file_parts[1].split("\n");
            for (String swap_values : swaps) {
                String[] swap_nums = swap_values.split("-");
                int num1 = Integer.parseInt(swap_nums[0]) - 1;
                int num2 = Integer.parseInt(swap_nums[1]) - 1;
                int temp;

                temp = tracks.get(num2);
                tracks.set(num2, tracks.get(num1));
                tracks.set(num1, temp);
            }

            // Get track value
            int test_idx = Integer.parseInt(file_parts[2]);
            int result = tracks.get(test_idx-1);
            System.out.println(result);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
