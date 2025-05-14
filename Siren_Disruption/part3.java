import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class part3 {
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
                int low = Math.min(num1, num2);
                int high = Math.max(num1, num2);

                int block_size = Math.min((tracks.size() - high), (high - low));
                for (int offset = 0; offset < block_size; offset++){
                    int temp = tracks.get(low + offset);
                    tracks.set(low + offset, tracks.get(high + offset));
                    tracks.set(high + offset, temp);
                }
            }

            // Get track value
            int test_idx = Integer.parseInt(file_parts[2]);
            int result = tracks.get(test_idx-1);
            System.out.println("Part 3: " + result);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
