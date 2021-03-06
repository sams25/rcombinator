# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

rcpp_simulate_without_flags_random <- function(num_seq, seq_length, point_mutation_model, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, recomb_mean, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging) {
    invisible(.Call(`_retrocombinator_rcpp_simulate_without_flags_random`, num_seq, seq_length, point_mutation_model, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, recomb_mean, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging))
}

rcpp_simulate_with_flags_random <- function(num_seq, seq_length, point_mutation_model, num_sensitive_posns, inactive_probability, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, max_total_copies, recomb_mean, selection_threshold, fam_proportion, fam_percentage, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging) {
    invisible(.Call(`_retrocombinator_rcpp_simulate_with_flags_random`, num_seq, seq_length, point_mutation_model, num_sensitive_posns, inactive_probability, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, max_total_copies, recomb_mean, selection_threshold, fam_proportion, fam_percentage, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging))
}

rcpp_simulate_without_flags_specified <- function(init_seqs, init_seq_index, point_mutation_model, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, recomb_mean, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging) {
    invisible(.Call(`_retrocombinator_rcpp_simulate_without_flags_specified`, init_seqs, init_seq_index, point_mutation_model, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, recomb_mean, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging))
}

rcpp_simulate_with_flags_specified <- function(init_seqs, init_seq_index, point_mutation_model, num_sensitive_posns, inactive_probability, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, max_total_copies, recomb_mean, selection_threshold, fam_proportion, fam_percentage, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging) {
    invisible(.Call(`_retrocombinator_rcpp_simulate_with_flags_specified`, init_seqs, init_seq_index, point_mutation_model, num_sensitive_posns, inactive_probability, num_jumps, timestep, burst_probability, burst_mean, max_active_copies, max_total_copies, recomb_mean, selection_threshold, fam_proportion, fam_percentage, file_out, num_out_tags, num_out_init, num_out_seqs, num_out_pair, to_randomise, to_seed, seed, sequence_numbering, family_numbering, logging))
}

