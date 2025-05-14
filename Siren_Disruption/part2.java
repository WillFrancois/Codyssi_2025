import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class part2 {
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
            for (int i = 0; i < swaps.length; i++) {
                int X = Integer.parseInt(swaps[i % swaps.length].split("-")[0]) - 1;
                int Y = Integer.parseInt(swaps[i % swaps.length].split("-")[1]) - 1;
                int Z = Integer.parseInt(swaps[(i + 1) % swaps.length].split("-")[0]) - 1;

                int temp = tracks.get(Y);
                int temp2 = tracks.get(Z);

                tracks.set(Y, tracks.get(X));
                tracks.set(Z, temp);
                tracks.set(X, temp2);
            }

            // Get track value
            int test_idx = Integer.parseInt(file_parts[2]);
            int result = tracks.get(test_idx-1);
            System.out.println("Part 2: " + result);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
